#include <iostream>
using namespace std;
const int size = 3;

char board[size][size];

void building_board()
{
    for (int i = 0; i < size; ++i)
        {
        for (int j = 0; j < size; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void show_board()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j];
            if (j < size - 1)
                cout << '|';
        }
        cout << endl;
        if (i < size - 1)
            cout << "-----" << endl;
    }
}

bool move_valid(int row, int col)
{
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
}

bool win_check(char player)
{
    for (int i = 0; i < size; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    for (int i = 0; i < size; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool draw_check()
{
    for (int i = 0; i < size; ++i)
        {
        for (int j = 0; j < size; ++j)
         {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {

cout<<"*******WELCOME TO THE TIC-TAC-TOE GAME*******"<<endl;
cout<<endl<<"LET ME DRAW THE BOARD FOR YOU"<<endl;
    char currentPlayer = 'X';
    bool win = false;
    bool draw = false;

    building_board();

    do {
        cout << "Displaying  board:" << endl;
        show_board();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row [0-2] and column [0-2]): ";
        cin >> row >> col;

        if (move_valid(row, col))
            {
            board[row][col] = currentPlayer;

            if (win_check(currentPlayer))
                {
                cout << "Player " << currentPlayer << " wins!" << endl;
                win = true;
            }
            else if (draw_check())
            {
                cout << "It's a draw!" << endl;
                draw = true;
            }
             else
                {
                if (currentPlayer == 'X')
                {
    currentPlayer = 'O';
                }
else
{
    currentPlayer = 'X';
}

            }
        }
         else
            {
            cout << "Invalid move. Try again." << endl;
        }
    }
     while (!win && !draw);

    cout << "Final board:" << endl;
    show_board();

    cout<<endl<<"HOPE YOU ENJOY MY GAME AND PROJECT"<<endl;

    cout << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        building_board();
        main();
    }

    return 0;
}

