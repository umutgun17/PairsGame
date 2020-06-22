#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

//  time Label which shows time
class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer();
    QTimer *timer;
    QLabel *label;
    int counter;

};

#endif // MYTIMER_H
