#include "mygrid.h"
#include "card.h"

MyGrid::MyGrid(QTimer *timer) : QGridLayout(){
    this->timer = timer;
}

void MyGrid::check_colors(){
    bool all_same = true;
    QString prev = "";
    for (int i = 0; i < this->count(); ++i)
    {
      Card *widget = qobject_cast<Card*> (this->itemAt(i)->widget());

    }

    if(all_same){
        this->timer->stop();
        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Cancel);
    }
}
