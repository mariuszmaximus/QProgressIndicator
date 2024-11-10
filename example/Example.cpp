#include "Example.h"

#include <QHBoxLayout>

#include "QProgressIndicator.h"

Example::Example(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *layout = new QHBoxLayout();

    QProgressIndicator* indicator1 = new QProgressIndicator(this); 
    layout->addWidget(indicator1);
    indicator1->setType(QProgressIndicator::line_rotate);
    indicator1->start();

    QProgressIndicator* indicator2a = new QProgressIndicator(this);
    layout->addWidget(indicator2a);
    indicator2a->setBallCount(4);
    indicator2a->setType(QProgressIndicator::ball_rotate);
    indicator2a->start();

    QProgressIndicator* indicator2b = new QProgressIndicator(this);
    layout->addWidget(indicator2b);
    indicator2b->setBallCount(8);
    indicator2b->setType(QProgressIndicator::ball_rotate);
    indicator2b->start();

    QProgressIndicator* indicator2c = new QProgressIndicator(this);
    layout->addWidget(indicator2c);
    indicator2c->setBallCount(16);
    indicator2c->setType(QProgressIndicator::ball_rotate);
    indicator2c->start();


    QProgressIndicator* indicator3 = new QProgressIndicator(this);
    layout->addWidget(indicator3);
    indicator3->setType(QProgressIndicator::line_scale);
    indicator3->setInterval(125);
    indicator3->start();

    QProgressIndicator* indicator4 = new QProgressIndicator(this);
    layout->addWidget(indicator4);
    indicator4->setType(QProgressIndicator::circle_rotate);
    indicator4->start();

    setLayout(layout);
}
