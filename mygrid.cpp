#include "mygrid.h"
#include "card.h"
#include <QEventLoop>
#include<QDebug>
MyGrid::MyGrid(QTimer *timer) : QGridLayout(){
    this->timer = timer;
}

void MyGrid::check_colors(){

    Card* temp = 0;
    int countDisable = 1; // ?????
    qInfo() << "----------";
    for (int i = 0; i < this->count(); ++i)
    {

        Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());



        if(widget->isEnabled() && widget->text() != "..."){



            if(temp != 0 && temp->text() != ""){
                if(temp->text() == widget->text()){
                    temp->setEnabled(false);
                    widget->setEnabled(false);

                    temp = 0;

                } else {

                    QEventLoop loop;
                    QTimer::singleShot(500, &loop, &QEventLoop::quit);
                    loop.exec();

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

        qInfo() << "C++ Style Info Message" << widget->isEnabled();
        if(!widget->isEnabled()) {
            countDisable ++;
        }

    }

    if(countDisable == 30) {
        QMessageBox msgBox;
        msgBox.setText("win");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Cancel);
    }


}
