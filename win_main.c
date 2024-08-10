#ifndef UNICODE
#define UNICODE
#endif 

#include <stdio.h>
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
        HINSTANCE hInstance, 
        HINSTANCE hPrevInstance,
        PSTR lpCmdLine, 
        int nCmdShow
    ) 
{

    // Register window class
    const wchar_t CLASS_NAME[] = L"Sample window class";
    const wchar_t MAIN_WINDOW_NAME[] = L"Test window";

    struct screen_props
    {
        int dim_y;
        int dim_x;
    };

    struct screen_props sp = {.dim_y = 800, .dim_x = 600};

    // This has to be initialized to 0's, otherwise registering the
    // class will fail and hwnd will resolve to NULL
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
    // hInstance = GetModuleHandle(NULL);
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,     // Class name
        MAIN_WINDOW_NAME, // Window name
        WS_OVERLAPPEDWINDOW,

        // origin and dimensions
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,

        NULL,           // Parent window
        NULL,           // Menu
        hInstance,      // Instance handle
        NULL            // Additional application data
    );

    if (hwnd == NULL)
    {
        printf("hwnd is NULL: %d", hwnd);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        // The TranslateMessage function is related to keyboard input. 
        // It translates keystrokes (key down, key up) into characters. 
        // You do not really have to know how this function works; 
        // just remember to call it before DispatchMessage.
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // MessageBoxW(
    //     NULL, 
    //     TEXT("Hello WinAPI Graphical User Interface"), 
    //     TEXT("Welcome"), 
    //     0
    // );

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;

            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}