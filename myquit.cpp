#include "myquit.h"

MyQuit::MyQuit(const QString& text, QWidget* parent) : QPushButton(text, parent)
{

}

void MyQuit::onPressedQuit(){
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

