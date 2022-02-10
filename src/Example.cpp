#include "Example.h"

#include "QProgressIndicator.h"

Example::Example(QWidget *parent) : QWidget(parent) {

    setFixedSize(4*80+16, 64); // 4 widgets x 80 pixels wide + 16 pixel offset

    QProgressIndicator* indicator1 = new QProgressIndicator(this);
    indicator1->setGeometry(16, 16, 64, 32);
    indicator1->setType(QProgressIndicator::line_rotate);
    indicator1->start();

    QProgressIndicator* indicator2 = new QProgressIndicator(this);
    indicator2->setGeometry(96, 16, 64, 32);
    indicator2->setType(QProgressIndicator::ball_rotate);
    indicator2->start();

    QProgressIndicator* indicator3 = new QProgressIndicator(this);
    indicator3->setGeometry(176, 16, 64, 32);
    indicator3->setType(QProgressIndicator::line_scale);
    indicator3->setInterval(125);
    indicator3->start();

    QProgressIndicator* indicator4 = new QProgressIndicator(this);
    indicator4->setGeometry(256, 16, 64, 32);
    indicator4->setType(QProgressIndicator::circle_rotate);
    indicator4->start();
}

Example::~Example() {
}

