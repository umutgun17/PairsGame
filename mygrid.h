#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include <QTimer>
 #include "card.h"
#include <QLabel>

class MyGrid : public QGridLayout
{
    Q_OBJECT

public:
    MyGrid(QTimer* timer,QLabel* score);
    QTimer* timer;
    QLabel* scoreLabel;
    int scoreInt;

public slots:
    void check_colors();
};


#endif // MYGRID_H
