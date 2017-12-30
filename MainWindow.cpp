#include "MainWindow.h"
#include "ui_MainWindow.h"

#include<QDebug>
#include <Qsci/qsciscintilla.h>
#include "QsciLexerGlsl.h"
#include <Qsci/qscilexercpp.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0
    /** 设置代码编辑框 **/
    m_code_edit =new QsciScintilla(this);
    m_code_edit->setGeometry(200,0,920,720);
    QsciLexerGLSL *textLexer = new QsciLexerGLSL;//创建一个词法分析器
    QsciAPIs*apis = new QsciAPIs(textLexer);
    if(!apis->load(QString("glsl.api")))
          qDebug()<<"读取文件失败";
       else
          apis->prepare();
    m_code_edit->setLexer(textLexer);//给QsciScintilla设置词法分析器
    m_code_edit->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    m_code_edit->setMarginLineNumbers(0,true);//对该页边启用行号
    m_code_edit->setMarginWidth(0,50);//设置页边宽度
    m_code_edit->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源
    m_code_edit->setAutoCompletionCaseSensitivity(false);   //设置自动补全大小写敏感
    m_code_edit->setAutoCompletionThreshold(1);    //设置每输入一个字符就会出现自动补全的提示
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
