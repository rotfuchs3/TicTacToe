//
// Created by skwasigr on 05.08.25.
//

#include "LogicSlave.h"

int LogicSlave::start_game(){

    //status.clear_borard();
    game_open = true;
    return 1;
}


void LogicSlave::wait_for_move(){
/*     legal_move = check_legal_move(row,col);
        if(legal_move==1) std::cout << "The input is not in the range (1-3)"<<std::endl;
        if(legal_move==2) std::cout << "The selected field is already picked"<<std::endl;
    }while(legal_move==1 || legal_move==2 );
    // all fine but for the array one indecies starting with 0
    status.move(row-1,col-1,currentPlayer);
    move_cnt++;
    status.print_board();
    unsigned you_won = check_board_win();
    std::cout<<"Make you move Player "<<currentPlayer<<"! Row(1-3): ";
            std::cin>>row;

//check if leagal moves
        if(legal_move==2) std::cout << "The selected field is already picked"<<std::endl;
    }while(legal_move==1 || legal_move==2 );
    // all fine but for the array one indecies starting with 0
    status.move(row-1,col-1,currentPlayer);
    move_cnt++;
    statuvoid Logic::wait_for_move(){
    unsigned row, col,legal_move;
    std::cout<<"For changing the settings please Enter for row or column 10"<<std::endl;
    do{
    std::cout<<"Make you move Player "<<currentPlayer<<"! Row(1-3): ";
            std::cin>>row;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Bad entry.  Enter a NUMBER Row(1-3): ";
            std::cin >> row;
        }
    std::cout<<"Col(1-3): ";
    std::cin>>col;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Bad entry.  Enter a NUMBER Col(1-3): ";
            std::cin >> col;
        }

    if (row==10 || col==10){open_settings(); return;}
    //check if leagal moves
     legal_move = check_legal_move(row,col);
        if(legal_move==1) std::cout << "The input is not in the range (1-3)"<<std::endl;
        if(legal_move==2) std::cout << "The selected field is already picked"<<std::endl;
    }while(legal_move==1 || legal_move==2 );
    // all fine but for the array one indecies starting with 0
    status.move(row-1,col-1,currentPlayer);
    move_cnt++;
    status.print_board();
    unsigned you_won = check_board_win();
s.print_board();
    unsigned you_won = check_board_win();

    if(you_won!=0){
        std::cout<<"Grats, Player "<<currentPlayer<<", you win!\n"<<std::endl;
        end_game();
        return;
    }

    if (move_cnt==9)
    {
        end_game();
        std::cout<<"Its a tie again \n"<<std::endl;
    }

    nextPlayer(); */
}

void LogicSlave::move(unsigned x, unsigned y,unsigned player){
    if (player == 1 && x<3 && y<3)
    {
        board[x][y] = player;
    } else if (player == 2 && x<3 && y<3)
    {
        board[x][y] = player;
    }
    move_cnt++;
}


/**
 * checks if the input is a legal move
 * @param row of the move
 * @param col umn of the moveField
 * @return status of these move: 0: move is legal, 1: move out of bounce (1-3), 2: field already blocked
 */
unsigned LogicSlave::check_legal_move(unsigned row, unsigned col) const
{
    if (row > 3 || col > 3) return 1;
    unsigned cell = board[row][col];
    if (cell==1||cell==2) return 2;

    //all fine
    return 0;
}

void LogicSlave::open_settings(){
 /*   unsigned settingChoice;

    std::cout << "Welcome in the settings:"<<std::endl;
    start:std::cout<<"For changing the Player 1 smbole: "<<player_symbol1<<" Please enter 11" <<std::endl;
    std::cout<<"For changing the Player 2 smbole: "<<status.player_symbol2<<"    Please enter 12" <<std::endl;
    std::cout<<"Continue: Please enter 20"<<std::endl;
    std::cout<<"New Game: Please enter 21"<<std::endl;
    std::cout<<"End Game: Please enter 22"<<std::endl;
    std::cin>>settingChoice;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry.  Enter '11' or '12'': ";
        std::cin >> settingChoice;
    }
    if(settingChoice==11)
    {
        std::cout<<" Enter the new symbol for Player 1 "<<std::endl;
        char symbol;
        std::cin>>symbol;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Bad entry.  Enter only on characters: ";
            std::cin >> symbol;
        }
        change_player_symbol(1,symbol);
    }
    if(settingChoice==12)
    {
        std::cout<<" Enter the new symbol for Player 2 "<<std::endl;
        char symbol;
        std::cin>>symbol;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Bad entry.  Enter only on characters: ";
            std::cin >> symbol;
        }
        change_player_symbol(2,symbol);
    }
    if(settingChoice==20) return;
    if(settingChoice==21) {start_game(); return;}
    if(settingChoice==22) {end_game(); return;}
    std::cout<<"Something else"<<std::endl;
    goto start;*/
}
void LogicSlave::end_game(){
    game_open = false;
    std::cout<<"Thank you for playing\n"<<std::endl;
}

/**
 * check if one player wins
 * @return 0: nobody won 1: player1 wins 2: player2 wins 3: all 9 fields full without a win.
 */
unsigned LogicSlave::check_board_win()
{

    unsigned player_control_diagonal=board[1][1];
    // the left to right diagonal
    if (player_control_diagonal!=0 && player_control_diagonal== board[0][0] &&  player_control_diagonal== board[2][2])
        return player_control_diagonal;
    if (player_control_diagonal!=0 && player_control_diagonal== board[2][0] &&  player_control_diagonal== board[0][2])
        return player_control_diagonal;

    //check for 3 same symbols in a row colomn
    for (int i=0;i<3;i++)
    {
        unsigned player_control_row=3,player_control_col=3;
        player_control_col=board[i][0];
        player_control_row=board[0][i];

        // win in these col
        if (player_control_row!=0 && player_control_row== board[i][1] &&  player_control_row== board[i][2])
            return player_control_row;
        // win in these col
        if (player_control_col!=0 && player_control_col== board[1][i] &&  player_control_col== board[2][i])
            return player_control_col;
    }

    // no win on the board
    if (move_cnt !=9)
        return 0;
    else
        return 3;
}
