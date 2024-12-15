#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// 检查在给定位置放置皇后是否安全
int is_safe(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    // 检查同一列是否已有皇后，遍历当前行之前的所有行
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // 检查左上方对角线是否有皇后冲突
    int i, j;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // 检查右上方对角线是否有皇后冲突
    for (i = row, j = col; i >= 0 && j < BOARD_SIZE; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// 使用回溯法解决八皇后问题
int solve_n_queens(int board[BOARD_SIZE][BOARD_SIZE], int row) {
    // 如果已经成功放置完8个皇后（即遍历完所有行），则打印出当前的棋盘布局作为一种解决方案
    if (row == BOARD_SIZE) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j] == 1? 'Q' : '.');
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }

    int found_solution = 0;
    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < BOARD_SIZE; col++) {
        // 检查在当前位置放置皇后是否安全
        if (is_safe(board, row, col)) {
            // 如果安全，则在该位置放置皇后（标记为1）
            board[row][col] = 1;
            // 递归调用函数，继续放置下一行的皇后，并记录是否找到了解决方案
            found_solution = solve_n_queens(board, row + 1) || found_solution;
            // 如果后续放置皇后的过程中发现无法完成放置（即该分支无解），回溯，将当前位置的皇后移除（标记为0）
            board[row][col] = 0;
        }
    }

    return found_solution;
}

int main() {
    // 初始化棋盘，所有位置初始化为0，表示没有皇后
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // 调用函数开始解决八皇后问题
    solve_n_queens(board, 0);

    return 0;
}
