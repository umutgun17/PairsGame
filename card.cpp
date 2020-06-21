#include "card.h"
#include <QMessageBox>
Card::Card(const QString& text,int & openCardCount,Card * preCard, QWidget* parent) : QPushButton("...", parent)
{
    textField = text;
    QPalette pal = palette();

    pal.setColor(QPalette::Button, QColor(Qt::green));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

    status="closed";
    this->openCardCount=&openCardCount;

   this->preCard=preCard;
}
void Card::onPressed(){


    if(status=="closed"){
        //if(*openCardCount>1) return;
        (*openCardCount)++;




        QPalette pal = palette();

        pal.setColor(QPalette::Button, QColor(Qt::white));

        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText(textField);
        update();
    status="open";

    if(!preCard){
        this->preCard=this;
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("YOU MATCH!");
        msgBox.exec();
        msgBox.setStandardButtons(QMessageBox::Cancel);
    }

    }
    else if(status=="open"){
        (*openCardCount)--;
        QPalette pal = palette();

        pal.setColor(QPalette::Button, QColor(Qt::green));

        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText("...");
        update();
    status="closed";

    }


}


