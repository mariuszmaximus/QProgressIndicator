#include "QProgressIndicator.h"

#include <QDebug>
#include <QPoint>
#include <QPoint>
#include <QtCore/qglobal.h>
#include <QtGlobal>

#define SPIN_INTERVAL 100 // Set timer to wake up every 100ms.

QProgressIndicator::QProgressIndicator(QWidget *parent) : QWidget(parent) {

  _type = QProgressIndicator::line_rotate;
  _interval = SPIN_INTERVAL;
  _angle = 0;
  _scale = 0.0f;
  _color = Qt::black;

  _ballCount = 8;

  // setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  // setFocusPolicy(Qt::NoFocus);

  _timer = new QTimer();

  connect(_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

QProgressIndicator::~QProgressIndicator() {

  stop();

  delete _timer;
}

void QProgressIndicator::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e)

  if (!_timer->isActive()) {
    return;
  }

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  switch (_type) {
  case QProgressIndicator::line_rotate:
    drawRotateLine(&painter);
    break;
  case QProgressIndicator::line_scale:
    drawScaleLine((&painter));
    break;
  case QProgressIndicator::ball_rotate:
    drawRotateBall(&painter);
    break;
  case QProgressIndicator::circle_rotate:
    drawRotateCircle(&painter);
    break;
  }
}

void QProgressIndicator::start() { _timer->start(_interval); }

void QProgressIndicator::stop() {

  _timer->stop();

  update(); // Force an update to erate the indicator from the view.
}

int QProgressIndicator::type() { return _type; }

void QProgressIndicator::setType(int type) { _type = type; }

const QColor &QProgressIndicator::color() { return _color; }

void QProgressIndicator::setColor(const QColor &color) { _color = color; }

int QProgressIndicator::interval() { return _interval; }

void QProgressIndicator::setInterval(int interval) { _interval = interval; }

int QProgressIndicator::ballCount() { return _ballCount; }

void QProgressIndicator::setBallCount(int ballCount) { _ballCount = ballCount; }


void QProgressIndicator::onTimeout() {

  switch (_type) {
  case line_rotate:
  case ball_rotate:
    _angle = (_angle + 45) % 360;
    break;
  case circle_rotate:
    _angle = (_angle + 45) % 360;
    break;
  case line_scale:
    _scale += 0.1f;
    _scale = _scale > .5f ? 0.0f : _scale;
    break;
  }

  update();
}

void QProgressIndicator::drawRotateLine(QPainter *painter) {

  int width = qMin(this->width(), this->height());

  int outerRadius = (width - 4) * 0.5f;
  int innerRadius = outerRadius * 0.42f;

  int capsuleHeight = outerRadius - innerRadius;
  int capsuleWidth = (width > 32) ? capsuleHeight * .32f : capsuleHeight * .40f;
  int capsuleRadius = capsuleWidth / 2;

  for (int i = 0; i < 8; i++) {

    QColor color = _color;

    color.setAlphaF(1.0f - (i / 8.0f));
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);

    painter->save();

    painter->translate(rect().center());
    painter->rotate(_angle - i * 45.0f);

    painter->drawRoundedRect(-capsuleWidth * 0.5,
                             -(innerRadius + capsuleHeight), capsuleWidth,
                             capsuleHeight, capsuleRadius, capsuleRadius);

    painter->restore();
  }
}

void QProgressIndicator::drawScaleLine(QPainter *painter) {

  int height = qMin(this->width(), this->height());

  qreal lineWidth = height * 0.15f;
  qreal lineHeight = height * 0.9f;
  qreal lineRadius = lineWidth / 2.0f;
  qreal lineGap = lineWidth;
  qreal margin = (this->width() - lineWidth * 5 - lineGap * 4) / 2.0f;

  for (int i = 0; i < 5; i++) {

    painter->setPen(Qt::NoPen);
    painter->setBrush(_color);

    int tmp = _scale * 10 + i + 1;
    if (tmp > 5) {
      tmp = 5 - tmp % 5;
    }

    qreal scale = 0.5f + tmp * 0.1f;
    qreal h = lineHeight * scale;

    painter->save();

    painter->translate(
        QPointF(margin + (lineWidth + lineGap) * i, this->height() / 2));

    painter->drawRoundedRect(0, -h / 2.0f, lineWidth, h, lineRadius,
                             lineRadius);

    painter->restore();
  }
}

void QProgressIndicator::drawRotateBall(QPainter *painter) {

  int width = qMin(this->width(), this->height());
  double capsuleRadius = width/2.0 * 50.0/100.0 / 2.0;
  double outerRadius = width/2.0;
  double innerRadius = width/2.0 - capsuleRadius*2;

  for (int i = 0; i < _ballCount; i++) {

    QColor color = _color;

    color.setAlphaF(1.0f - (i / (double)_ballCount));

    painter->setPen(Qt::NoPen);
    painter->setBrush(color);

    // radius in range 100%..50% 
    qreal radius = capsuleRadius * (1.0f - (i / (((double)_ballCount-1)*2)));

    painter->save();

    painter->translate(rect().center());
    painter->rotate(_angle - i * (360.0/(_ballCount)));

    // orginal wrong version 
    // QPointF centre = QPointF(-capsuleRadius, -(innerRadius + capsuleRadius));
    QPointF centre = QPointF(0, -(innerRadius + capsuleRadius));
    painter->drawEllipse(centre, radius , radius );

    painter->restore();
  }
}

void QProgressIndicator::drawRotateCircle(QPainter *painter) {

  // My version is based on ProgressInfiniteBar from :
  // https://github.com/przemek83/wble

  int width = qMin(this->width(), this->height());
  int penwidth = 5;

  QRectF r = QRect(0 + penwidth, 
                    0 + penwidth, 
                    width - (2 * penwidth),
                   width - (2 * penwidth));

  QPen pen(_color);
  pen.setWidth(penwidth);
  pen.setCapStyle(Qt::RoundCap);

  painter->setPen(pen);
  painter->setBrush(_color);

  // move rect into center 
  painter->translate( QPoint((this->width()-width)/2, (this->height()-width)/2));

  int startAngle = 0.0;
  int spanAngle = 45 * 16;

  startAngle = (0.0 + _angle) * 16;
  painter->drawArc(r, -startAngle, -spanAngle);

  startAngle = (120.0 + _angle) * 16;
  painter->drawArc(r, -startAngle, -spanAngle);

  startAngle = (240.0 + _angle) * 16;
  painter->drawArc(r, -startAngle, -spanAngle);
}
