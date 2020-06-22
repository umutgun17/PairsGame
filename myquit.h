#ifndef MYQUIT_H
#define MYQUIT_H
#include <QPushButton>
#include <QPalette>
#include <QApplication>
#include <QProcess>

class MyQuit : public QPushButton
{
    Q_OBJECT

public:

    MyQuit(const QString& text, QWidget* parent = 0);


public slots:
    void onPressedQuit();
};

#endif // MYQUIT_H
