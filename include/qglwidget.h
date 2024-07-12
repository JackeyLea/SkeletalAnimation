#ifndef QGLWIDGET_H
#define QGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_0>
#include <QSurfaceFormat>
#include <QKeyEvent>

class QGLWidget : public QOpenGLWidget,public QOpenGLFunctions_3_0
{
public:
    QGLWidget(QWidget *parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    void keyPressEvent(QKeyEvent *event);

private:
    bool mFullScreen;
};

#endif // QGLWIDGET_H
