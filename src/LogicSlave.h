//
// Created by skwasigr on 05.08.25.
//

#ifndef LOGICSLAVE_H
#define LOGICSLAVE_H

#include "../TicTacToeUI/FieldWindow.h"


class LogicSlave {
public:

     LogicSlave ()
    {
        currentPlayer=1;
        move_cnt = 0;
        game_open = false;
    }

    ~LogicSlave()= default;

    int start_game();
    void wait_for_move();
    unsigned check_legal_move(unsigned row, unsigned col) const;
    void move(unsigned x, unsigned y,unsigned player);
    void change_player_symbol(unsigned player,char symbol);
    void open_settings();
    void end_game();
    void nextPlayer();

private:
    unsigned move_cnt;
    unsigned currentPlayer;
    bool game_open;
    unsigned check_board_win();
    unsigned board [3][3]= {{0,0,0},{0,0,0},{0,0,0}};

};



#endif //LOGICSLAVE_H
