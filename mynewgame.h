#ifndef MYNEWGAME_H
#define MYNEWGAME_H
#include <QPushButton>
#include <QPalette>
#include <QApplication>
#include <QProcess>

class MyNewGame : public QPushButton
{
    Q_OBJECT

public:

    MyNewGame(const QString& text, QWidget* parent = 0);


public slots:
    void onPressedQuit();
};

#endif // MYNEWGAME_H
