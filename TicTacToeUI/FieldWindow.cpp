#include "FieldWindow.h"

FieldWindow::FieldWindow(QWidget *parent)
    : QWidget(parent)//t, gameState(Logic(*this))
    //, ui(new Ui::FieldWindow)
{
    //ui->setupUi(this);
    for (int i = 0; i < 9; ++i)
            fieldButtons[i] = createButton(QString::number(i),&FieldWindow::fieldClicked);

    QLabel* statusMessage = new QLabel(tr("Let the game start"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    for (int i =0 ; i < 9 ; i++ ) {
        int row = i/3;
        int col = i%3;
        mainLayout ->addWidget(fieldButtons[i],row,col);
    }

    // adding the status line below the grid
    mainLayout->addWidget(statusMessage,3,0,1,3);

    setLayout(mainLayout);

    setWindowTitle(tr("TicTacToe"));
}

FieldWindow::~FieldWindow()
{
    //delete ui;
}

void FieldWindow::fieldClicked()
{
    auto sender = this->sender();

    for(int i = 0; i< 9;i++){
        if(sender == fieldButtons[i])
            this->fieldButtons[i]->setText(QString::fromStdString("X"));
    }

}
void FieldWindow::menuSelected()
{

}

template<typename PointerToMemberFunction>
QPushButton* FieldWindow::createButton(const QString &text, const PointerToMemberFunction &member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, &QPushButton::clicked, this, member);
    return button;
}

