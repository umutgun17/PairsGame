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
#include "mynewgame.h"
#include <QDebug>

// shuffle function to change index of elements
std::vector<QString> shuffle(std::vector<QString> arr)
{
    std::srand(std::time(0));
    for (int i = 0; i < 1000; i++)
    {
        std::swap(arr.at(rand() % (arr.size())), arr.at(rand() % (arr.size())));
    }
    return arr;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // main widget for our UI
    QWidget *main = new QWidget;

    // vertical layout
    // 2 row, first one for Time - Score Label
    // and new game and quit Buttons
    // second row for Game Card Buttons
    QVBoxLayout *vLayout = new QVBoxLayout(main);

    // first row horizontal layout for
    // Time - Score Label and new game and quit Buttons
    QHBoxLayout *hLayout = new QHBoxLayout();

    // Time Label object
    MyTimer *myTimer = new MyTimer();
    hLayout->addWidget(myTimer->label);

    // Score Label object
    QLabel *score = new QLabel;
    score->setText("Score: 0");
    hLayout->addWidget(score);

    // spacer between labels and buttons
    QSpacerItem *hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding);
    hLayout->addSpacerItem(hSpacer);

    // new game button
    MyNewGame *newBtn = new MyNewGame("New Game");
    hLayout->addWidget(newBtn);
    QObject::connect(newBtn, SIGNAL(clicked()), newBtn, SLOT(onPressedQuit()));

    // Quit Button
    QPushButton *quitBtn = new QPushButton("Quit");
    hLayout->addWidget(quitBtn);
    QObject::connect(quitBtn, SIGNAL(clicked()), &app, SLOT(quit()));

    // first row of vertical layout
    vLayout->addLayout(hLayout);

    // Game Card Grid
    MyGrid *grid = new MyGrid(myTimer, score);

    // word list
    std::vector<QString> fullList = std::vector<QString>{"death", "agency", "union", "tea", "significance", "unit", "category",
                                                         "enthusiasm", "disease", "girlfriend", "trainer", "role", "safety", "sister", "atmosphere", "umut", "gun", "emin", "deniz", "boun", "cmpe", "2020", "230"};

    // shuffled vector
    std::vector<QString> tempfullList = shuffle(fullList);

    // get first 15 card
    std::vector<QString> gridList = std::vector<QString>();
    for (int a = 0; a < 15; a++)
    {
        gridList.push_back(tempfullList[a]);
        gridList.push_back(tempfullList[a]);
    }
    gridList = shuffle(gridList);

    // fill grid
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            Card *buttons = new Card(gridList[row * 6 + col]);
            QObject::connect(buttons, SIGNAL(clicked()), buttons, SLOT(onPressed()));
            QObject::connect(buttons, SIGNAL(clicked()), grid, SLOT(check_matches()));
            grid->addWidget(buttons, row, col, 1, 1);
        }
    }

    // second row of vertical layout
    vLayout->addLayout(grid);

    // bottom empty space
    QSpacerItem *vSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vLayout->addSpacerItem(vSpacer);

    main->setWindowTitle("Card Match Game");
    main->resize(640, 480);
    main->show();

    return app.exec();
}
