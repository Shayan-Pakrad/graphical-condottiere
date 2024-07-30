#include "showcarddialog.h"
#include "ui_showcarddialog.h"

showCardDialog::showCardDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showCardDialog)
{
    ui->setupUi(this);
}

showCardDialog::~showCardDialog()
{
    delete ui;
}

void showCardDialog::on_btnOk_clicked()
{
    this->hide();
}

