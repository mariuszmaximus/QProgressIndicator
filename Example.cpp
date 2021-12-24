#include "Example.h"

#include "QProgressIndicator.h"

Example::Example(QWidget *parent) : QWidget(parent) {

    setFixedSize(256, 64);

    QProgressIndicator *indicator = new QProgressIndicator(this);
    indicator->setGeometry(16, 16, 64, 32);
    indicator->setType(QProgressIndicator::line_rotate);
    indicator->start();

    indicator = new QProgressIndicator(this);
    indicator->setGeometry(96, 16, 64, 32);
    indicator->setType(QProgressIndicator::ball_rotate);
    indicator->start();

    indicator = new QProgressIndicator(this);
    indicator->setGeometry(176, 16, 64, 32);
    indicator->setType(QProgressIndicator::line_scale);
    indicator->setInterval(125);
    indicator->start();
}

Example::~Example() {
}

