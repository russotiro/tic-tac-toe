//
// Created by RussellS on 12/17/20.
//

#ifndef IDKWID_TICTACTOE_H
#define IDKWID_TICTACTOE_H


class TicTacToe {

public:

    TicTacToe();
    void run();

private:

    void draw_board();
    void input_loop();
    char curr_turn();

    bool assert_valid_indices(int row, int column);
    bool detect_win();
    bool detect_tie();

    static const int BOARD_SIZE = 3;

    char board[BOARD_SIZE][BOARD_SIZE];
    bool X_turn = true;
    char win_check_chars[2] = {'X', 'O'};

};


#endif //IDKWID_TICTACTOE_H
