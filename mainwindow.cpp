#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set the fixed size of the screen
    this->setFixedSize(1000, 600);

    // Set the background image
    QPixmap bkgnd("E:/Shayan/github_projects/Rakab Graphical/graphical-condottiere/assets/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
