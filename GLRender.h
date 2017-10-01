#ifndef GLRENDER_H
#define GLRENDER_H

#include<windows.h>
#include<opengl/glew.h>
#include<QMap>
#include<iostream>
#include<QDebug>
#include<string>
using namespace std;
class GLRender
{
public:
    GLRender(HWND hWnd);
    ~GLRender(){
        glDeleteProgram(m_glProgramHandle);
    }

    // 设置为当前 GL Context
    void useContext(){
        wglMakeCurrent(m_hDC, m_hRC);
    }
    void clearContext(){
        wglMakeCurrent(nullptr, nullptr);
    }

    void resize(int w,int h){
        m_height=h;
        m_width =w;
        useContext();
        //GLfloat ratio = (GLfloat)w / (GLfloat)h;
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glUniform2f(glGetUniformLocation(m_glProgramHandle, "resolution"), w, h);

    }

    void loadGlslCode(const string&code){
        CreateGLSL();

        useContext();
        /*
        if(m_glslFlagShader!=-1){
            glDetachShader(m_glProgramHandle, m_glslFlagShader);
            glDeleteShader(m_glslFlagShader);
            m_glslFlagShader=0;
        }
        */
        qDebug()<<"m_glslFlagShader"<< (m_glslFlagShader=glCreateShader(GL_FRAGMENT_SHADER));
        if (0 == m_glslFlagShader)
        {
            cerr << "ERROR : Create fragment shader failed" << endl;
        }
        const GLchar *vCodeArray[1] = { code.c_str() };
        glShaderSource(m_glslFlagShader, 1, vCodeArray, NULL);
        glCompileShader(m_glslFlagShader);
        GLint compileResult;
        glGetShaderiv(m_glslFlagShader, GL_COMPILE_STATUS, &compileResult);
        if (GL_FALSE == compileResult)
        {
            GLint logLen;
            //得到编译日志长度
            glGetShaderiv(m_glslFlagShader, GL_INFO_LOG_LENGTH, &logLen);
            if (logLen > 0)
            {
                char *log = (char *)malloc(logLen);
                GLsizei written;
                //得到日志信息并输出
                glGetShaderInfoLog(m_glslFlagShader, logLen, &written, log);
                cerr << "fragment shader compile log : " << endl;
                cerr << log << endl;
                free(log);//释放空间
            }
        }
        glAttachShader(m_glProgramHandle, m_glslFlagShader);
        glLinkProgram(m_glProgramHandle);
        GLint linkStatus;
        glGetProgramiv(m_glProgramHandle, GL_LINK_STATUS, &linkStatus);
        if (GL_FALSE == linkStatus)
        {
            cerr << "ERROR : link shader program failed" << endl;
            GLint logLen;
            glGetProgramiv(m_glProgramHandle, GL_INFO_LOG_LENGTH,
                &logLen);
            if (logLen > 0)
            {
                char *log = (char *)malloc(logLen);
                GLsizei written;
                glGetProgramInfoLog(m_glProgramHandle, logLen,
                    &written, log);
                cerr << "Program log : " << endl;
                cerr << log << endl;
            }
        }
        glUseProgram(m_glProgramHandle);
        m_uniformTimeHandle=glGetUniformLocation(m_glProgramHandle, "time");
        clearContext();
        resize(m_width,m_height);
    }

    void render(){
        useContext();
        glColor3f(0.f,0.f,0.f);
        glBindVertexArray(m_vaoHandle);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, ((GLuint*)NULL + (0)));
        glBindVertexArray(0);

        SwapBuffers(m_hDC);
        clearContext();
    }

    void setUniformTime(float time){
        useContext();
        glUniform1f(m_uniformTimeHandle,time);
    }

private:
    // 创造Context    No.1
    void InitGLContext();

    // 初始化  glew   No.2
    bool InitGlew();

    // 创造 AVO Handle    No.3
    void CreateVAO();

    // 创造 GLSL Program  No.4
    void CreateGLSL();
private:
    HGLRC   m_hRC;
    HDC     m_hDC;
    HWND    m_hWnd;

    GLint   m_height;
    GLint   m_width;

    GLuint  m_glProgramHandle;  //glCreateProgram();
    GLuint  m_vaoHandle;        //vertex array object
    GLuint  m_glslFlagShader;   //

    GLuint  m_uniformTimeHandle;
public:
    const GLfloat VAO_Points2d[8] =
    {1.0f   ,   1.0f    ,1.0f   ,   -1.0f   ,-1.0f  ,   -1.0f   ,-1.0f  ,   1.0f};
    const GLuint  VAO_Indexes[4]={0,1,2,3};
    const char*   GLSL_FLAG_DEFUAT="void main(){gl_FragColor=vec4(1,0.,0.1,1.0);}";
};

#endif // GLRENDER_H
