#include "mainwindow.hpp"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    MainWindow w;
    auto screenRect = QApplication::desktop()->rect();
    w.move(screenRect.center() - w.rect().center());
    w.show();

    return app.exec();
}
