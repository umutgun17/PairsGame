#include "mygrid.h"


MyGrid::MyGrid(MyTimer *timerLabel,QLabel* score) : QGridLayout(){
    this->timerLabel = timerLabel;
    this->scoreLabel=score;
    this->scoreInt=0;

    connect(timerLabel->timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

void MyGrid::check_matches(){

    Card* temp = 0;
    for (int i = 0; i < this->count(); ++i)
    {

        Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());



        if(widget->isEnabled() && widget->text() != "?"){



            if(temp != 0 && temp->text() != "?"){
                if(temp->text() == widget->text()){
                    temp->setEnabled(false);
                    temp->status="done";
                    widget->setEnabled(false);
                    widget->status="done";
                    this->scoreInt+=1;
                    this->scoreLabel->setText("Score : "+ QString::number(this->scoreInt));
                    temp = 0;

                } else {

                    QEventLoop loop;
                    QTimer::singleShot(300, &loop, &QEventLoop::quit);
                    loop.exec();

                    temp->setText("?");
                    temp->status = "closed";
                    QPalette pal = temp->palette();
                    pal.setColor(QPalette::Button, QColor(Qt::green));
                    temp->setPalette(pal);

                    QPalette pal2 = widget->palette();
                    pal2.setColor(QPalette::Button, QColor(Qt::green));
                    widget->setPalette(pal2);

                    widget->setText("?");
                    widget->status = "closed";
                    temp = 0;
                }
            }

            temp = widget;

        }



    }

    if( this->scoreInt == 15) {
        this->timerLabel->timer->stop();

        for (int i = 0; i < this->count(); ++i)
        {
            Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());
            widget->hide();
        }

        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Ok);
    }


}

void MyGrid::timeoutSlot(){
    timerLabel->counter += 1;
    timerLabel->label->setText("Time (secs): "+ QString::number(timerLabel->counter));
    if(timerLabel->counter>=30){
        this->timerLabel->timer->stop();

        for (int i = 0; i < this->count(); ++i)
        {
            Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());
            widget->hide();
        }

        QMessageBox msgBox;
        msgBox.setText("You failed!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

    }
}
