#include "card.h"

Card::Card(const QString &text, QWidget *parent) : QPushButton("?", parent)
{
    textField = text;
    QPalette pal = palette();

    pal.setColor(QPalette::Button, QColor(Qt::green));

    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
    status = "closed";
}
void Card::onPressed()
{
    // flip card from closed state to open state
    if (status == "closed")
    {
        QPalette pal = palette();
        pal.setColor(QPalette::Button, QColor(Qt::gray));
        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText(textField);
        update();
        // status="open";  // it enables flipping card without pair
    }
    // flip card from open state to closed state
    else if (status == "open")
    {
        QPalette pal = palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        setFlat(true);
        setAutoFillBackground(true);
        setPalette(pal);
        setText("?");
        update();
        status = "closed";
    }
}
