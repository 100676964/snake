#include <QApplication>
#include "screen.h"
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    screen win;
    win.show();
    return app.exec();

}
