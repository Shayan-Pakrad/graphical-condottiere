#ifndef SHOWCARDDIALOG_H
#define SHOWCARDDIALOG_H

#include <QDialog>

namespace Ui {
class showCardDialog;
}

class showCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit showCardDialog(QWidget *parent = nullptr);
    ~showCardDialog();

    Ui::showCardDialog *ui;

private slots:
    void on_btnOk_clicked();

private:

};

#endif // SHOWCARDDIALOG_H
