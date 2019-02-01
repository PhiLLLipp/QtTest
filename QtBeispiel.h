#ifndef QTBEISPIEL_H
#define QTBEISPIEL_H
#include <QFont>
#include <QDial>
#include <QSpinBox>
#include <QGridLayout>
#include <QPushButton>
#include "Zeichenflaeche.h"

class QtBeispiel : public QWidget {
public:
  QtBeispiel() {
    QPushButton *quit = new QPushButton("Ende");
    quit ->setFont(QFont("Helvetica", 16, QFont::Bold));
    connect(quit, SIGNAL(clicked()),qApp,SLOT(quit()));

    QDial *qdial = new QDial();
    qdial->setNotchesVisible(true);

    Zeichenflaeche *zeichenflaeche = new Zeichenflaeche;
    connect(qdial, SIGNAL(valueChanged(int)), zeichenflaeche, SLOT(setRadius(int)));

    QSpinBox *qspinbox = new QSpinBox;
    qspinbox->setFont(QFont("Helvetica", 12, QFont::StyleNormal));
    connect(qdial, SIGNAL(valueChanged(int)), qspinbox, SLOT(setValue(int)));
    connect(qspinbox, SIGNAL(valueChanged(int)), qdial, SLOT(setValue(int)));

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(qspinbox, 1, 0);
    gridLayout->addWidget(qdial, 2, 0);
    gridLayout->addWidget(zeichenflaeche, 0, 1, 3, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
  }
};
#endif
