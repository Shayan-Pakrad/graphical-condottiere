#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    //open player initializer window
    initPlayersWindow = new InitPlayersWindow(this);
    initPlayersWindow->show();

    // wait for the next button on initPlayersWindow to execute rest of the program
    connect(initPlayersWindow, &InitPlayersWindow::buttonClicked, this, &GameWindow::executeRestOfConstructor);

}

void GameWindow::executeRestOfConstructor() {

    // initialize players with input names and ages at the initPlayersWindow
    game.initPlayers(initPlayersWindow->players);


    // show the ui
    ui->setupUi(this);

    // set the fixed size of the screen
    this->setFixedSize(1000, 600);

    // Set the background image
    QPixmap bkgnd(":/assets/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

GameWindow::~GameWindow()
{
    delete ui;
}
