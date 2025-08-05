#include "FieldWindow.h"

FieldWindow::FieldWindow(QWidget *parent)
    : QWidget(parent), gameState(new LogicSlave())
    //, ui(new Ui::FieldWindow)
{
    //ui->setupUi(this);
    for (int i = 0; i < 9; ++i)
            fieldButtons[i] = createButton(QString(""),&FieldWindow::fieldClicked);

    statusMessage = new QLabel(tr("Let the game start"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    for (int i =0 ; i < 9 ; i++ ) {
        int row = i/3;
        int col = i%3;
        mainLayout ->addWidget(fieldButtons[i],row,col);
    }

    // adding the status line below the grid
    mainLayout->addWidget(statusMessage,3,0,1,3);

    createActions();
    createMenus();

    setLayout(mainLayout);

    setWindowTitle(tr("TicTacToe"));

    gameState->start_game();
}

FieldWindow::~FieldWindow()
{
    delete gameState;
}

void FieldWindow::createActions(){
    aNewGame = new QAction(QIcon::Normal,tr("&New Game"), this);
    aNewGame->setShortcuts(QKeySequence::New);
    aNewGame->setStatusTip(tr("Create a new Game"));
    connect(aNewGame, &QAction::triggered, this, &FieldWindow::menuNewGame);

    aRevert = new QAction(QIcon::Normal,tr("Revert"), this);
    aNewGame->setShortcuts(QKeySequence::New);
    aNewGame->setStatusTip(tr("Revert last move"));
    connect(aNewGame, &QAction::triggered, this, &FieldWindow::menuRevert);

    aRevert = new QAction(QIcon::Normal,tr("Change Player Symbol"), this);
    aNewGame->setShortcuts(QKeySequence::New);
    aNewGame->setStatusTip(tr("Change the symbole of a chosen player"));
    connect(aNewGame, &QAction::triggered, this, &FieldWindow::menuChangePlayerSymbol);
}

void FieldWindow::createMenus(){
    game = menuBar()->addMenu(tr("&Game"));
    game->addAction(aNewGame);
    game->addAction(aRevert);
    game->addAction(aChangePlayerSymbol);
}

void FieldWindow::change_player_symbol(unsigned player,char symbol)
{
    if (player == 1) player_symbol1 =symbol;
    else if (player == 2) player_symbol2 =symbol;
    else newStatusMsg("You can only change the symbol of player 1 or 2");
}

void FieldWindow::nextPlayer()
{
    if(currentPlayer==1) currentPlayer=2;
    else if(currentPlayer==2) currentPlayer=1;
}

void FieldWindow::newStatusMsg(std::string text)
{
    statusMessage->setText(QString::fromStdString(text));
}

template<typename PointerToMemberFunction>
QPushButton* FieldWindow::createButton(const QString &text, const PointerToMemberFunction &member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, &QPushButton::clicked, this, member);
    return button;
}

//------------------slots-----------------------

void FieldWindow::fieldClicked()
{
    if(gameState->game_open==true){
        auto sender = this->sender();

        char nextSymbol[1];
        if( currentPlayer==1)
            nextSymbol[0]=player_symbol1;
        else
            nextSymbol[0]=player_symbol2;

        std::printf("next Symbol %c",nextSymbol[0]);

        for(unsigned i = 0; i< 9;i++){
            if(sender == fieldButtons[i]){
                unsigned row = i/3, col =i%3;
                unsigned status =gameState->check_legal_move(row,col);
                if(status == 0){
                    gameState->move(row,col,currentPlayer);
                    this->fieldButtons[i]->setText(QString::fromStdString(nextSymbol));//str(nextSymbol)));
                    unsigned gamestatus = gameState->check_board_win();
                    if( gamestatus == 0) {
                        nextPlayer();
                        newStatusMsg("It is your move player "+std::to_string(currentPlayer));
                    }else if( gamestatus == 1||status == 2) {
                        newStatusMsg("Congraturalation player "+std::to_string(currentPlayer)+" You won this game!");
                        gameState->end_game();
                    }else if(gamestatus ==3) {
                        newStatusMsg("All fields are picked and no win. Its a draw!");
                        gameState->end_game();
                    }
                }else if(status==1) newStatusMsg("player "+std::to_string(currentPlayer)+" your move is out of the scope. How?");
                else if(status ==2) newStatusMsg("player "+std::to_string(currentPlayer)+" this field is already picked, Choose another one");

            }
        }
    }
}
void FieldWindow::menuNewGame()
{

}

void FieldWindow::menuRevert()
{

}

void FieldWindow::menuChangePlayerSymbol()
{

}


