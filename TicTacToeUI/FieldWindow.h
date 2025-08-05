#pragma once

#include "../src/LogicSlave.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QIcon>
#include <QMenuBar>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class FieldWindow; }
QT_END_NAMESPACE

class LogicSlave;

class FieldWindow : public QWidget
{
    Q_OBJECT

public:
    FieldWindow(QWidget *parent = nullptr);
    ~FieldWindow();
    LogicSlave* gameState;

    void move(unsigned x, unsigned y,unsigned player);
    //void revert();
    void print_board();
    unsigned get_borard_value(unsigned x, unsigned y);
    void clear_borard();
    void newStatusMsg(std::string text);


private:
    QPushButton *fieldButtons[9];
    template<typename PointerToMemberFunction>
    QPushButton *createButton(const QString &text, const PointerToMemberFunction &member);
    QLabel* statusMessage;
    QMenu *game;
    QAction *aNewGame;
    QAction *aRevert;
    QAction *aChangePlayerSymbol;


    void createActions();
    void createMenus();

    //helper for the game logic
    short currentPlayer=1;
    char player_symbol1,player_symbol2;
    void change_player_symbol(unsigned player,char symbol);
    void nextPlayer();




private slots:
    void fieldClicked();
    //void revertClicked();
    void menuNewGame();
    void menuRevert();
    void menuChangePlayerSymbol();

};
