#include "mygrid.h"
#include "card.h"
#include <QEventLoop>
#include<QDebug>
MyGrid::MyGrid(QTimer *timer,QLabel* score) : QGridLayout(){
    this->timer = timer;
    this->scoreLabel=score;
    this->scoreInt=0;
}

void MyGrid::check_colors(){

    Card* temp = 0;
    qInfo() << "----------";
    for (int i = 0; i < this->count(); ++i)
    {

        Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());



        if(widget->isEnabled() && widget->text() != "..."){



            if(temp != 0 && temp->text() != "..."){
                if(temp->text() == widget->text()){
                    temp->setEnabled(false);
                    temp->status="done";
                    widget->setEnabled(false);
                    widget->status="done";
                    qInfo() <<"done  geliyor "<<temp->text()<<"-"<<widget->textField;
                    this->scoreInt+=2;
                    this->scoreLabel->setText("Score : "+ QString::number(this->scoreInt));
                    temp = 0;

                } else {

                    QEventLoop loop;
                    QTimer::singleShot(500, &loop, &QEventLoop::quit);
                    loop.exec();
                    qInfo() <<"closed geliyor "<<temp->text();

                    temp->setText("...");
                    temp->status = "closed";
                    QPalette pal = temp->palette();
                    pal.setColor(QPalette::Button, QColor(Qt::green));
                    temp->setPalette(pal);

                    QPalette pal2 = widget->palette();
                    pal2.setColor(QPalette::Button, QColor(Qt::green));
                    widget->setPalette(pal2);

                    widget->setText("...");
                    widget->status = "closed";
                    temp = 0;
                }
            }

            temp = widget;

        }

        qInfo() << "C++ Style Info Message" << widget->isEnabled()<<" -  "<<widget->status<<"  score:"<<  this->scoreInt;


    }

    if( this->scoreInt == 30) {
        this->timer->stop();

        for (int i = 0; i < this->count(); ++i)
        {
            Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());
            widget->hide();
        }

        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Cancel);
    }


}
