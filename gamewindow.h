#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "initplayerswindow.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

    InitPlayersWindow *initPlayersWindow;

};

#endif // GAMEWINDOW_H
