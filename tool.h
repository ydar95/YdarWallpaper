#ifndef TOOL_H
#define TOOL_H

#include <functional>
#include <Windows.h>

namespace winHWND {
inline BOOL CALLBACK EnumWindowsProc(_In_ HWND   tophandle, _In_ LPARAM topparamhandle) {
    HWND workerw;
    if (FindWindowEx(tophandle, 0, L"SHELLDLL_DefView", 0) != 0)
    {
        workerw = FindWindowEx(0, tophandle, L"WorkerW", 0);
        ShowWindow(workerw, SW_HIDE);
    }
    return true;
}

inline HWND getWorker() {
    static int wp=0;

    HWND windowHandle= FindWindow(L"Progman",nullptr);
    SendMessageTimeout(windowHandle, 0x52c, (WPARAM)&wp, 0, SMTO_NORMAL, 0x3e8, 0);
    // 消息会生成两个WorkerW 顶级窗口 所以要枚举不包含“SHELLDLL_DefView”这个的 WorkerW 窗口 隐藏掉。
    EnumWindows(EnumWindowsProc,0);
    return windowHandle;
}
}

#endif // TOOL_H
