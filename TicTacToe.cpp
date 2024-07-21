#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkTie(const vector<vector<char>>& board);
bool placeMarker(vector<vector<char>>& board, int position, char marker);

int main() 
{
    vector<vector<char>> board = 
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int currentPlayer = 1;
    int moves = 0;
    bool gameover = false;

    while (!gameover) 
    {
        printBoard(board);

        char marker = (currentPlayer == 1) ? 'X' : 'O';

        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        int choice;
        cin >> choice;

        while (choice < 1 || choice > 9 || !placeMarker(board, choice, marker)) 
        {
            cout << "Invalid move. Please enter a number (1-9): ";
            cin >> choice;
        }

        if (checkWin(board, marker)) 
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            gameover = true;
        } 
        else if (checkTie(board)) 
        {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameover = true;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        moves++;
    }

    return 0;
}

void printBoard(const vector<vector<char>>& board) 
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << "| ";
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }
    return false;
}

bool checkTie(const vector<vector<char>>& board) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') 
            {
                return false; 
            }
        }
    }
    return true; 
}

bool placeMarker(vector<vector<char>>& board, int position, char marker) 
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (board[row][col] == 'X' || board[row][col] == 'O') 
    {
        return false; 
    } 
    
    else 
    {
        board[row][col] = marker;
        return true;
    }
}