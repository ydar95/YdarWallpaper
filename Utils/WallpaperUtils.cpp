#include "WallpaperUtils.h"
HWND workerw = nullptr;
inline BOOL CALLBACK EnumWindowsProc(_In_ HWND   tophandle, _In_ LPARAM topparamhandle) {
    //HWND workerw;
    if (FindWindowEx(tophandle, 0, L"SHELLDLL_DefView", nullptr) != nullptr)
    {
        workerw = FindWindowEx(0, tophandle, L"WorkerW", 0);
    }
    return true;
}

HWND WallpaperUtils::GetWallpaperParentHWND(){
    int res;
    HWND windowHandle = FindWindow(L"Progman", nullptr);
    SendMessageTimeout(windowHandle, 0x52c, 0 ,0, SMTO_NORMAL, 0x3e8,(PDWORD_PTR)&res);
    // ��Ϣ����������WorkerW �������� ����Ҫö�ٲ�������SHELLDLL_DefView������� WorkerW ���� ���ص�
    res=0;
    EnumWindows(EnumWindowsProc,(LPARAM)&res);
    ShowWindow(workerw,SW_HIDE);
    return windowHandle;
}
