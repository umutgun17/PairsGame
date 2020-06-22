#include "mynewgame.h"

MyNewGame::MyNewGame(const QString& text, QWidget* parent) : QPushButton(text, parent)
{

}

// New Game Button pressed
void MyNewGame::onPressedQuit(){
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

