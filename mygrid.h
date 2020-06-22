#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include <QTimer>
#include <QLabel>
#include <QEventLoop>
#include "mytimer.h"
#include "card.h"

// Card Game Main Block
// it checks score and match
// it checks time
// it has logic of the game
class MyGrid : public QGridLayout
{
    Q_OBJECT

public:
    // it takes pointer of timer Label which shows time
    // and score label which shows score
    MyGrid(MyTimer *timerLabel, QLabel *score);
    MyTimer *timerLabel;
    QLabel *scoreLabel;
    int scoreInt;
public slots:
    void check_matches();
    void timeoutSlot();
};

#endif // MYGRID_H
