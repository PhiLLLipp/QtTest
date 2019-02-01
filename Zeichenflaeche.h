#ifndef ZEICHENFLAECHE_H
#define ZEICHENFLAECHE_H
#include <QWidget>
#include <QPainter>

class Zeichenflaeche : public QWidget {
  Q_OBJECT
public:
  Zeichenflaeche() {
    aktuellerRadius = 2;
    setPalette(QPalette(QColor(255, 255, 255)));
    setAutoFillBackground(true);
  }

  int getRadius() const { return aktuellerRadius; }

  public slots:
  void setRadius(int radius) {
    if(radius < 1)
      radius = 1;
      aktuellerRadius = radius;
      update();
      emit radiusChanged(aktuellerRadius);
  }

  signals:
    void radiusChanged(int neuerRadius);

  protected:
    void paintEvent(QPaintEvent *event) {
      QPainter painter(this);
      painter.translate(0, rect().height());
      int offset = rect().height()/2;
      int r = aktuellerRadius;
      painter.drawEllipse(QRectF(offset-r, -offset-r, 2*r, 2*r));
    }

  private:
    int aktuellerRadius;
};
#endif
