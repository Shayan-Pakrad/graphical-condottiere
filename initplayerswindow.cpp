#include "initplayerswindow.h"
#include "ui_initplayerswindow.h"

#include <QMessageBox>

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

void InitPlayersWindow::on_btnNext_clicked()
{
    bool validation = true;

    if (ui->txtPlayer1Name->text().isEmpty() || ui->txtPlayer2Name->text().isEmpty() || ui->txtPlayer3Name->text().isEmpty() || ui->txtPlayer4Name->text().isEmpty()) {
        validation = false;
    }


    if (validation == false) {
        QMessageBox::information(this, "Check", "Please fill name boxes correctly");
    }

    else {

        Player player1{this->ui->txtPlayer1Name->text().toStdString(), this->ui->numPlayer1Age->value(), "blue"};
        Player player2{this->ui->txtPlayer2Name->text().toStdString(), this->ui->numPlayer2Age->value(), "red"};
        Player player3{this->ui->txtPlayer3Name->text().toStdString(), this->ui->numPlayer3Age->value(), "orange"};
        Player player4{this->ui->txtPlayer4Name->text().toStdString(), this->ui->numPlayer4Age->value(), "white"};

        players.push_back(player1);
        players.push_back(player2);
        players.push_back(player3);
        players.push_back(player4);

        emit buttonClicked();

        this->hide();
    }


}

