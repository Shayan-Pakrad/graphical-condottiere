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
        this->player1Name = this->ui->txtPlayer1Name->text().toStdString();
        this->player2Name = this->ui->txtPlayer2Name->text().toStdString();
        this->player3Name = this->ui->txtPlayer3Name->text().toStdString();
        this->player4Name = this->ui->txtPlayer4Name->text().toStdString();

        this->player1Age = this->ui->numPlayer1Age->value();
        this->player2Age = this->ui->numPlayer2Age->value();
        this->player3Age = this->ui->numPlayer3Age->value();
        this->player4Age = this->ui->numPlayer4Age->value();

        emit buttonClicked();

        this->hide();
    }


}

