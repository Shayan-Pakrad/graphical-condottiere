#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

#include "initplayerswindow.h"

#include "Game.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void executeRestOfConstructor();

private:
    Ui::GameWindow *ui;

    InitPlayersWindow *initPlayersWindow;

    Game game;

};

#endif // GAMEWINDOW_H
