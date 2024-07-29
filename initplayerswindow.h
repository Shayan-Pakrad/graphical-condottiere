#ifndef INITPLAYERSWINDOW_H
#define INITPLAYERSWINDOW_H

#include <QMainWindow>

namespace Ui {
class InitPlayersWindow;
}

class InitPlayersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InitPlayersWindow(QWidget *parent = nullptr);
    ~InitPlayersWindow();

    std::string player1Name;
    std::string player2Name;
    std::string player3Name;
    std::string player4Name;

    int player1Age;
    int player2Age;
    int player3Age;
    int player4Age;

signals:
    void buttonClicked();

private slots:
    void on_btnNext_clicked();

private:
    Ui::InitPlayersWindow *ui;
};

#endif // INITPLAYERSWINDOW_H
