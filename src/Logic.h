//
// Created by skwasigr on 14.06.25.
//

#ifndef LOGIC_H
#define LOGIC_H

#include "Field.h"

class Logic {
    public:
    Logic(Field stat)
    {
        status=stat;
        currentPlayer=1;
        move_cnt = 0;
        game_open = false;
    }

    ~Logic()= default;

    void start_game();
    void wait_for_move();
    unsigned check_legal_move(unsigned row, unsigned col);
    void change_player_symbol(unsigned player,char symbol);
    void open_settings();
    void end_game();
    void nextPlayer();

    private:
    Field status;
    unsigned move_cnt;
    unsigned currentPlayer;
    bool game_open;
    unsigned check_board_win();

};



#endif //LOGIC_H
