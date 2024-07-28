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

private:
    Ui::InitPlayersWindow *ui;
};

#endif // INITPLAYERSWINDOW_H
