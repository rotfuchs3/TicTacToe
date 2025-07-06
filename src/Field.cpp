//
// Created by skwasigr on 14.06.25.
//

#include "Field.h"

#include <iostream>

void Field::move(unsigned x, unsigned y,unsigned player){
    if (player == 1 && x<3 && y<3)
    {
        board[x][y] = player;
    } else if (player == 2 && x<3 && y<3)
    {
        board[x][y] = player;
    }
}

//void revert();
void Field::print_board(){
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            char c= ' ';
            if (board[row][col] == 1) c= player_symbol1;
            if (board[row][col] == 2) c= player_symbol2;
            std::cout<<" "<<c<<" ";
            if (col<2)
                std::cout<<"|";
            else std::cout<<" "<<std::endl;
        }
        if (row<2)
            for (int repeat = 0; repeat<3; repeat++)
                if (repeat<2) std::cout<<"----";
                else std::cout<<"---"<<std::endl;

    }

}

void Field::set_symbol_player(int player,char symbol){
    if (player==1)
        player_symbol1 = symbol;
    if (player==2)
        player_symbol2 = symbol;
}

void Field::clear_borard(){
    // goes row wise through the board
    for (auto & i : board){
        // goes through the coloumns of the row
        for (int  j : i)
        {
            j=0;
        }
    }
}


