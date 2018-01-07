#include "MainWidget.h"


#include <QListView>
#include <QLabel>
#include <QPushButton>
#include <QImage>
#include <QTextCodec>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QAbstractItemView>
#include <string>
#include <experimental/filesystem>
#include <algorithm>
#include <QDebug>

#include "WallpaperUtils.h"
using namespace std;
using namespace std::experimental::filesystem::v1;

#include "GLViewWidget.h"
#include "GUI/DiyListView.h"
MainWidget::MainWidget(QWidget *parent) :
    DiyWidget(parent)
{
    m_background_view=new GLViewWidget();
    m_background_view->showFullScreen();

    SetParent((HWND)m_background_view->winId(),WallpaperUtils::GetWorkerW());

    m_display_list_view=new DiyListView(this);
    m_display_list_view->setGeometry(10,55,580,510);
    m_display_list_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QLabel *versions_label=new QLabel(this);
    versions_label->setText(u8"Version :0.1 By ydar95");
    versions_label->setGeometry(800,575,140,12);


    QLabel *label_border_ptr=new QLabel(this);
    label_border_ptr->setText("");
    label_border_ptr->setGeometry(599,54,322,182);
    label_border_ptr->setStyleSheet("border:  2px solid grey;border-radius: 5px;text-align: center;");
    m_gl=new GLViewWidget(this);
    m_gl->setGeometry(600,55,320,180);


    m_btn=new QPushButton(this);
    m_btn->setGeometry(600,250,320,40);

    m_glsl_off_render=new GlslPaintSurface(nullptr,QSize(256,144));

    connect(m_btn, SIGNAL(released()), this, SLOT(m_slots_btn_release()));
    connect(m_display_list_view , SIGNAL(doubleClicked(const QModelIndex&)),this, SLOT(on_listview_doubleClicked(const QModelIndex&)));

    display("./glsl_code");

    m_index=-1;
}

MainWidget::~MainWidget(){
    delete m_background_view;
}

void MainWidget::m_slots_btn_release(){
    //m_background_view->hide();
    if(m_index!=-1){
        m_background_view->stop();
        m_background_view->setFragmentByFile(m_files_vec[m_index]);
        m_background_view->start();
        m_gl->stop();
    }
    //display("./glsl_code");
}

void MainWidget::display(const QString &dir){
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string dir_std= code->fromUnicode(dir).data();

    path root_path(dir_std);
    m_files_vec.clear();
    directory_iterator begin_itr(root_path), end_itr;
    for (auto itr = begin_itr; itr != end_itr; itr++) {
        if (!is_directory(itr->path())) {
            //if(itr->path().extension()=="frag")
            m_files_vec.push_back(QString::fromStdString(itr->path().string()));
        }
    }
    std::sort(m_files_vec.begin(), m_files_vec.end());

    m_display_list_view->getModel()->clear();
    for(int i=0;i<m_files_vec.size();i++){
        m_glsl_off_render->setFragmentByFile(m_files_vec[i]);
        m_glsl_off_render->render();
        m_display_list_view->push_back(QString("%1").arg(i),m_glsl_off_render->grabFramebuffer());
    }
}

void MainWidget::on_listview_doubleClicked(const QModelIndex &index){
    m_gl->stop();
    m_gl->setFragmentByFile(m_files_vec[index.row()]);
    m_gl->start();
    m_index=index.row();
    qDebug()<<"on_listview_doubleClicked"<<index.row();

}
