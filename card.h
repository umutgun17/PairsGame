#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>

class Card : public QPushButton
{
    Q_OBJECT

public:

    Card(const QString& text, QWidget* parent = 0);
    QString textField;
    QString status; // open close disabled

public slots:
    void onPressed();
};

#endif // COLORBUTTON_H
