//
// Created by RussellS on 12/17/20.
//

#include "tictactoe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '~';
}

void TicTacToe::run()
{
    cout << "The empty board is printed below.\n\n";
    draw_board();
    input_loop();
}

void TicTacToe::draw_board()
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void TicTacToe::input_loop()
{
    int row, column;
    cout << "X goes first.\n"
            "When entering a position, please enter in this format: row column\n"
            "Enter a position: ";
    while (cin >> row) {
        cin >> column;
        cout << endl;

        if (assert_valid_indices(row, column)) {
            board[row - 1][column - 1] = curr_turn();
            draw_board();
            if (detect_win()) {
                cout << curr_turn() << " wins!\n";
                return;
            } else if (detect_tie()) {
                cout << "It's a tie!\n";
                return;
            }
            X_turn = !X_turn;
        } else {
            cout << "Invalid indices. Try again.\n\n";
            draw_board();
        }

        cout << "Enter a position: ";
    }
}

char TicTacToe::curr_turn()
{
    if (X_turn)
        return 'X';
    else
        return 'O';
}

bool TicTacToe::assert_valid_indices(int row, int column)
{
    return board[row - 1][column - 1] == '~';
}

bool TicTacToe::detect_win()
{
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == win_check_chars[k] &&
                board[i][1] == win_check_chars[k] &&
                board[i][2] == win_check_chars[k])
                return true;
            if (board[0][i] == win_check_chars[k] &&
                board[1][i] == win_check_chars[k] &&
                board[2][i] == win_check_chars[k])
                return true;
        }
        // Diagonal cases
        if (board[0][0] == win_check_chars[k] &&
            board[1][1] == win_check_chars[k] &&
            board[2][2] == win_check_chars[k])
            return true;
        if (board[0][2] == win_check_chars[k] &&
            board[1][1] == win_check_chars[k] &&
            board[2][0] == win_check_chars[k])
            return true;
    }
    return false;
}

bool TicTacToe::detect_tie() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '~')
                return false;
        }
    }
    return true;
}
