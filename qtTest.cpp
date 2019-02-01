#include <QApplication>
#include "QtBeispiel.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QtBeispiel widget;
  widget.setGeometry(100, 100, 400, 300);
  widget.show();
  return app.exec();
}
