#include "Example.h"
#include <QApplication>

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    Example w;
    w.resize(800,100);
    w.show();

    return a.exec();
}

