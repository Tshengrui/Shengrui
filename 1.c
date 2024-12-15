#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80  // 定义代码雨的宽度（可根据终端宽度调整）
#define HEIGHT 20  // 定义代码雨的高度（可根据终端高度调整）
#define FALL_SPEED 10000  // 定义代码雨下落速度，单位是微秒，数值越小速度越快

// 定义代码雨的字符集合，可以自行丰富添加更多字符
char code_characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// 初始化ncurses库并设置相关属性
void initNcurses() {
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // 设置颜色对，前景色为绿色，背景色为黑色
    cbreak();
    noecho();
    curs_set(0);  // 隐藏光标
}

// 关闭ncurses库
void closeNcurses() {
    endwin();
}

// 初始化代码雨数据结构，返回表示代码雨状态的二维字符数组
char** initCodeRain() {
    char** codeRain = (char**)malloc(WIDTH * sizeof(char*));
    for (int i = 0; i < WIDTH; i++) {
        codeRain[i] = (char*)malloc(HEIGHT * sizeof(char));
        for (int j = 0; j < HEIGHT; j++) {
            codeRain[i][j] =' ';  // 修正为正确的空格字符赋值
        }
    }
    return codeRain;
}

// 更新代码雨的位置，模拟下落效果
void updateCodeRain(char** codeRain) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = HEIGHT - 1; j > 0; j--) {
            codeRain[i][j] = codeRain[i][j - 1];
        }
        codeRain[i][0] = code_characters[rand() % (sizeof(code_characters) - 1)];
    }
}

// 打印代码雨到终端屏幕
void printCodeRain(char** codeRain) {
    attron(COLOR_PAIR(1));  // 启用设置好的颜色对
    for (int i = 0; i < HEIGHT; i++) {
        move(i, 0);  // 移动光标到对应行开头
        for (int j = 0; j < WIDTH; j++) {
            printw("%c", codeRain[j][i]);
        }
    }
    attroff(COLOR_PAIR(1));  // 关闭颜色对
    refresh();
}

int main() {
    srand((unsigned int)time(NULL));
    initNcurses();

    char** codeRain = initCodeRain();

    while (1) {
        updateCodeRain(codeRain);
        printCodeRain(codeRain);
        usleep(FALL_SPEED);
    }

    // 释放内存
    for (int i = 0; i < WIDTH; i++) {
        free(codeRain[i]);
    }
    free(codeRain);

    closeNcurses();
    return 0;
}
