#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include "mytimer.h"
#include "mygrid.h"
#include "card.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *main = new QWidget;
    QVBoxLayout *vLayout = new QVBoxLayout(main);
    QHBoxLayout *hLayout = new QHBoxLayout();
    MyTimer myTimer;
    hLayout->addWidget(myTimer.label);

    QLabel *score = new QLabel;
    score->setText("Score: 0");
    hLayout->addWidget(score);

    QSpacerItem *hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding);
    hLayout->addSpacerItem(hSpacer);

    QPushButton *newBtn = new QPushButton("New Game");
    hLayout->addWidget(newBtn);
    QObject::connect(newBtn, SIGNAL(clicked()), &app, SLOT(quit()));

    QPushButton *quitBtn = new QPushButton("Quit");
    hLayout->addWidget(quitBtn);
    QObject::connect(quitBtn, SIGNAL(clicked()), &app, SLOT(quit()));

    vLayout->addLayout(hLayout);

    MyGrid *grid = new MyGrid(myTimer.timer);

    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            Card *buttons = new Card("X");
            //QObject::connect(buttons, SIGNAL(clicked()), buttons, SLOT(change_color()));
            QObject::connect(buttons, SIGNAL(clicked()), grid, SLOT(check_colors()));
            grid->addWidget(buttons, row, col, 1, 1);
        }
    }

    vLayout->addLayout(grid);

    QSpacerItem *vSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vLayout->addSpacerItem(vSpacer);

    main->setWindowTitle("Card Match Game");
    main->resize(640, 480);
    main->show();

    return app.exec();
}
