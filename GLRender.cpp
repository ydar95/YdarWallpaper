#include "GLRender.h"
#include <windows.h>
#include <opengl/glew.h>
#include <iostream>
#include <QDebug>
using namespace std;
GLRender::GLRender(HWND hWnd):
    m_glProgramHandle(-1),
    m_vaoHandle(-1),
    m_glslFlagShader(-1),
    m_height(100),
    m_width(100)
{
    m_hWnd =hWnd;
    InitGLContext();
    InitGlew();
    CreateVAO();
    //CreateGLSL();
    loadGlslCode(this->GLSL_FLAG_DEFUAT);

    qDebug()<<this->m_glProgramHandle   <<this->m_glslFlagShader    <<this->m_vaoHandle
           <<this->m_hDC                <<this->m_hRC               <<this->m_hWnd    ;
}

void GLRender::InitGLContext()
{
    m_hDC = GetDC(m_hWnd);
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

    useContext();
}

bool GLRender::InitGlew(){
    useContext();
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cerr << "Error initializing GLEW: " << glewGetErrorString(err) << endl;
        return false;
    }
    return true;
}

void GLRender::CreateVAO(){
    useContext();

    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint positionBufferHandle = vboHandles[0];
    GLuint indexesHandle	=vboHandles[1];
    //绑定VBO以供使用
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    //加载数据到VBO
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat),VAO_Points2d, GL_STATIC_DRAW);
    glGenVertexArrays(1, &m_vaoHandle);
    glBindVertexArray(m_vaoHandle);
    glEnableVertexAttribArray(0);//顶点坐标
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexesHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), VAO_Indexes, GL_STATIC_DRAW);

    clearContext();
}

void GLRender::CreateGLSL(){
    useContext();
    if(m_glProgramHandle!=-1)
        glDeleteProgram(m_glProgramHandle);
    qDebug()<<"m_glProgramHandle"<<(m_glProgramHandle=glCreateProgram());
    if (!m_glProgramHandle){
        cerr << "ERROR : create program failed" << endl;
    }
    clearContext();

    //resize(m_width,m_height);
}

