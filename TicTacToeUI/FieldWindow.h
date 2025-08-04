#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../src/Field.h"
//#include "../src/Logic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FieldWindow; }
QT_END_NAMESPACE

class FieldWindow : public QWidget
{
    Q_OBJECT

public:
    FieldWindow(QWidget *parent = nullptr);
    ~FieldWindow();
    //Logic gameState;

    char player_symbol1,player_symbol2;
    void move(unsigned x, unsigned y,unsigned player);
    //void revert();
    void print_board();
    unsigned get_borard_value(unsigned x, unsigned y);
    void set_symbol_player(int player,char symbol);
    void clear_borard();


private:
    Ui::FieldWindow *ui;
    QPushButton *fieldButtons[9];
    template<typename PointerToMemberFunction>
    QPushButton *createButton(const QString &text, const PointerToMemberFunction &member);

private slots:
    void fieldClicked();
    //void revertClicked();
    void menuSelected();


};
