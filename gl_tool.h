#ifndef GL_TOOL_H
#define GL_TOOL_H


#include<opengl/glew.h>
#include<Windows.h>
#include<iostream>
using namespace std;
namespace gl {


inline void InitGLContext(HWND hWnd,HGLRC& m_hRC , HDC &m_hDC)
{
    m_hDC = GetDC(hWnd);
    //初始化像素格式
    static    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),    //上述格式描述符的大小
        1,                                //版本号
        PFD_DRAW_TO_WINDOW |              //格式支持窗口
        PFD_SUPPORT_OPENGL |              //格式必须支持OpenGL
        PFD_DOUBLEBUFFER,                 //必须支持双缓冲
        PFD_TYPE_RGBA,                    //申请RGBA 格式
        24,                               //选定色彩深度
        0, 0, 0, 0, 0, 0, 0, 0,           //忽略RGBA
        0,                                //无累加缓存
        0, 0, 0, 0,                       //忽略聚集位
        32,                               //32位Z-缓存(深度缓存)
        0,                                //无蒙板缓存
        0,                                //无辅助缓存
        PFD_MAIN_PLANE,                   //主绘图层
        0,                                //Reserved
        0, 0, 0                           //忽略层遮罩
    };
    //选择一个最适合pfd描述的像素格式索引值
    int nPixelFormat = ChoosePixelFormat(m_hDC, &pfd);
    //为DC设置像素格式
    SetPixelFormat(m_hDC, nPixelFormat, &pfd);
    //创建RC
    m_hRC = wglCreateContext(m_hDC);
    wglMakeCurrent(m_hDC, m_hRC);
}

inline bool InitGlew(){
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cerr << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
        return false;
    }
    return true;
}



}

#endif // GL_TOOL_H
