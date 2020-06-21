#include "mytimer.h"

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    label = new QLabel("Time (secs): 0");
    counter = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));

    timer->start(1000);
}

void MyTimer::MyTimerSlot()
{
    counter += 1;
    label->setText("Time (secs): "+ QString::number(this->counter));
    if(counter>=180){
        this->timer->stop();
        QMessageBox msgBox;
        msgBox.setText("You failed!");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();
    }
}

