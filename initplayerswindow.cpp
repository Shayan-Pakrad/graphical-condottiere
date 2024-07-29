#include "initplayerswindow.h"
#include "ui_initplayerswindow.h"

InitPlayersWindow::InitPlayersWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InitPlayersWindow)
{
    ui->setupUi(this);

    // set the fixed size of the screen
    this->setFixedSize(1000, 600);

}

InitPlayersWindow::~InitPlayersWindow()
{
    delete ui;
}
