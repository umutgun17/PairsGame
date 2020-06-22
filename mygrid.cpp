#include "mygrid.h"

// Game Cards block
// it handles logic of game
MyGrid::MyGrid(MyTimer *timerLabel,QLabel* score) : QGridLayout(){
    this->timerLabel = timerLabel;
    this->scoreLabel=score;
    this->scoreInt=0;

    // connect timeout to timeoutslot for checking time limit
    connect(timerLabel->timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

// this method is triggered when a button is clicked
// it traverses all cards and checks if a match exists or not
void MyGrid::check_matches(){

    // "temp" keeps previous Card Object
    Card* temp = 0;

    // iterating all card in grid
    for (int i = 0; i < this->count(); ++i)
    {
        // cast grid item to card
        Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());

        // if current card is enabled and open( text is open )
        // continue check
        if(widget->isEnabled() && widget->text() != "?"){

            // if previous card exist and current card is not closed
            if(temp != 0 && temp->text() != "?"){

                // if previous card and current card matches
                // make them disabled and increase score
                if(temp->text() == widget->text()){
                    temp->setEnabled(false);
                    temp->status="done";
                    widget->setEnabled(false);
                    widget->status="done";
                    this->scoreInt+=1;
                    this->scoreLabel->setText("Score : "+ QString::number(this->scoreInt));
                    temp = 0;

                }
                // else, if they are not same, show them for miliseconds
                // and close them
                else {

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

            // set previous card
            temp = widget;

        }
    }

    // if gamer reaches max score, game finished
    if( this->scoreInt == 15) {
        // stop timer
        this->timerLabel->timer->stop();

        // hide all cards
        for (int i = 0; i < this->count(); ++i)
        {
            Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());
            widget->hide();
        }

        // prompt to show victory
        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Ok);
    }


}


// it is triggered for each second
// it checks
void MyGrid::timeoutSlot(){
    // time
    timerLabel->counter += 1;
    // label
    timerLabel->label->setText("Time (secs): "+ QString::number(timerLabel->counter));

    // time limit check
    if(timerLabel->counter>=180){
        // stop timer
        this->timerLabel->timer->stop();

        // hide all cards
        for (int i = 0; i < this->count(); ++i)
        {
            Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());
            widget->hide();
        }

        // prompt to show timeout
        QMessageBox msgBox;
        msgBox.setText("You lose!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

    }
}
