#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>

class Card : public QPushButton
{
    Q_OBJECT

public:
    Card(const QString& text, QWidget* parent = 0);

public slots:

};

#endif // COLORBUTTON_H
