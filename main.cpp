#include <iostream>

#include "src/Field.h"
#include "src/Logic.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "TicTacToe";
    std::cout << "Hello and welcome to " << lang << "!\n";

    Field ui = Field();
    //ui.print_board();
    Logic game = Logic(ui);
    game.start_game();


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}