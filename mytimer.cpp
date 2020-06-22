#include "mytimer.h"

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    label = new QLabel("Time (secs): 0");
    counter = 0; // time
    timer->start(1000); // for each 1 second interval, it creates timeout() Signal
}


