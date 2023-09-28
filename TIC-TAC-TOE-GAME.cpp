#include <bits/stdc++.h>

const int BOARD_SIZE = 3;
const char EMPTY_CELL = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void displayBoard(const std::vector<std::vector<char>> &board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                std::cout << "|";
        }
        std::cout << "\n";
        if (i < BOARD_SIZE - 1)
            std::cout << "-----\n";
    }
}

bool checkWin(const std::vector<std::vector<char>> &board, char player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw(const std::vector<std::vector<char>> &board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY_CELL)
                return false;
        }
    }
    return true;
}

bool playAgain()
{
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main()
{
    std::cout << "Welcome to Tic-Tac-Toe!\n";

    while (true)
    {
        std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY_CELL));
        char currentPlayer = PLAYER_X;

        while (true)
        {
            std::cout << "Current board:\n";
            displayBoard(board);

            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row [0-2] and column [0-2]): ";
            std::cin >> row >> col;

            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY_CELL)
            {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer))
            {
                std::cout << "Player " << currentPlayer << " wins!\n";
                displayBoard(board);
                break;
            }

            if (checkDraw(board))
            {
                std::cout << "It's a draw!\n";
                displayBoard(board);
                break;
            }

            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }

        if (!playAgain())
            break;
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
