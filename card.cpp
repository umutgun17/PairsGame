#include "card.h"

Card::Card(const QString& text, QWidget* parent) : QPushButton(text, parent)
{

    QPalette pal = palette();

    pal.setColor(QPalette::Button, QColor(Qt::blue));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();

}

