//
// Created by skwasigr on 14.06.25.
//

#ifndef FIELD_H
#define FIELD_H
#include <string>


class Field {
public:
    Field()
    {
       player_symbol1 ='X' ;
       player_symbol2 ='O' ;
    }
    char player_symbol1,player_symbol2;
    ~Field()= default;
    void move(unsigned x, unsigned y,unsigned player);
    //void revert();
    void print_board();
    inline unsigned get_borard_value(unsigned x, unsigned y) const { return board[x][y];}
    void set_symbol_player(int player,char symbol);
    void clear_borard();

private:
    unsigned board [3][3]= {{0,0,0},{0,0,0},{0,0,0}};

};



#endif //FIELD_H
