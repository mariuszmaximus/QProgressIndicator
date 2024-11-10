#pragma once

#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

class QProgressIndicator : public QWidget {

  Q_OBJECT

  Q_PROPERTY(int _type READ type WRITE setType)
  Q_PROPERTY(QColor _color READ color WRITE setColor)
  Q_PROPERTY(int _interval READ interval WRITE setInterval)

public:
  QProgressIndicator(QWidget *parent = 0);
  ~QProgressIndicator();

  enum { line_rotate, line_scale, ball_rotate, circle_rotate };

  void paintEvent(QPaintEvent *e);

  void start();
  void stop();

  int type();
  void setType(int type);

  const QColor &color();
  void setColor(const QColor &color);

  int interval();
  void setInterval(int interval);

private slots:
  void onTimeout();

private:
  void drawRotateLine(QPainter *painter);
  void drawScaleLine(QPainter *painter);
  void drawRotateBall(QPainter *painter);
  void drawRotateCircle(QPainter *painter);

private:
  int _type;
  int _interval;
  QColor _color;

  int _angle;
  qreal _scale;

  QTimer *_timer;
};
