#include "card.h"
#include <QMessageBox>
#include <QDebug>
Card::Card(const QString& text, QWidget* parent) : QPushButton("...", parent)
{
    textField = text;
    QPalette pal = palette();

    pal.setColor(QPalette::Button, QColor(Qt::green));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
    status="closed";

}
void Card::onPressed(){
    if(status=="closed"){
        QPalette pal = palette();
        pal.setColor(QPalette::Button, QColor(Qt::gray));
        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText(textField);
        update();
     //   status="open";
    }
    else if(status=="open"){
        QPalette pal = palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText("...");
        update();
        status="closed";
        qInfo() <<"closed geliyor ";

    }

}
void Card::onPressedQuit(){
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

