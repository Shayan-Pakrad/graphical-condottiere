#include "initplayerswindow.h"
#include "ui_initplayerswindow.h"

InitPlayersWindow::InitPlayersWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InitPlayersWindow)
{
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

InitPlayersWindow::~InitPlayersWindow()
{
    delete ui;
}
