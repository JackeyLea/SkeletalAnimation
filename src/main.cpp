#include "qglwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGLWidget w;
    w.show();
    return a.exec();
}
