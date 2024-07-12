#include "qglwidget.h"

QGLWidget::QGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    ,mFullScreen(false)
{
    QSurfaceFormat format;
    format.setSamples(24);

    setFormat(format);
    showNormal();
}

void QGLWidget::initializeGL()
{
    initializeOpenGLFunctions();//初始化OpenGL上下文内容
    glClearColor(0.0f,0.0f,0.0f,1.0f);//将缓冲区清空为RGBA指定的颜色
    //使用颜色缓冲区、深度缓冲区、RGBA、alpha支持
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_RGBA|GL_ALPHA_BITS);
    glEnable(GL_DEPTH_TEST);//使用深度缓冲区测试

    qDebug()<<"Used OpenGL Version: "<<context()->format().majorVersion()<<"."<<context()->format().minorVersion();

    qDebug()<<"OpenGL info: ";
    qDebug()<<"             VENDOR:        "<<(const char*)glGetString(GL_VENDOR);
    qDebug()<<"             RENDERER:      "<<(const char*)glGetString(GL_RENDERER);
    qDebug()<<"             VERSION:       "<<(const char*)glGetString(GL_VERSION);
    qDebug()<<"             GLSL VERSION:  "<<(const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
}

void QGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,qMax(h,1));//设置视角范围
    update();//qt自带的界面刷新函数
}

void QGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//清除屏幕和深度缓存
    glLoadIdentity();	// 重置当前的模型观察矩阵

    update();
}

void QGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_F2:
    {
        mFullScreen=!mFullScreen;
        if(mFullScreen){
            showFullScreen();
        }else{
            showNormal();
        }
        update();
        break;
    }
    case Qt::Key_Escape:
    {
        qApp->exit();
        break;
    }
    }
}
