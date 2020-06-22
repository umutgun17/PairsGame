#ifndef CARD_H
#define CARD_H
#include <QPushButton>
#include <QPalette>
#include <QApplication>
#include <QProcess>

class Card : public QPushButton
{
    Q_OBJECT

public:

    Card(const QString& text, QWidget* parent = 0);
    QString textField;
    QString status; // open close disabled

public slots:
    void onPressed();
    void onPressedQuit();
};

#endif // CARD_H
