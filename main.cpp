#include <QApplication>
#include "LarkyCharmGui.h"
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
LarkyCharmGui *window = new LarkyCharmGui;
window->show();
return app.exec();
}

