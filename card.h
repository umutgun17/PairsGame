#ifndef CARD_H
#define CARD_H
#include <QPushButton>
#include <QPalette>
#include <QApplication>
#include <QProcess>
#include <QMessageBox>

// Game Card Button, it can be opened
// It inherits from QPushButton
// and it is customized button
// color, text, status
class Card : public QPushButton
{
    Q_OBJECT

public:
    Card(const QString &text, QWidget *parent = 0);
    QString textField;
    QString status; // open ,close, disabled

public slots:
    void onPressed();
};

#endif // CARD_H
