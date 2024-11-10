#include "Example.h"

#include <QHBoxLayout>

#include "QProgressIndicator.h"

Example::Example(QWidget *parent) : QWidget(parent) {

    QHBoxLayout *layout = new QHBoxLayout();

    QProgressIndicator* indicator1 = new QProgressIndicator(this); 
    layout->addWidget(indicator1);
    indicator1->setType(QProgressIndicator::line_rotate);
    indicator1->start();

    QProgressIndicator* indicator2 = new QProgressIndicator(this);
    layout->addWidget(indicator2);
    indicator2->setType(QProgressIndicator::ball_rotate);
    indicator2->start();

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
