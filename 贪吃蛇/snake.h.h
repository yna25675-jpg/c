#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 22
#define COL 32

// 颜色枚举
enum {
    COLOR_DEFAULT = 7,
    COLOR_WHITE = 15,
    COLOR_RED = 12,
    COLOR_LIGHT_BLUE = 11,
    COLOR_BLUE = 9
};

// 标记枚举
enum {
    EMPTY,
    WALL,
    FOOD,
    HEAD,
    BODY
};

// 方向键枚举
enum {
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,
    SPACE = 32,
    ARROW = 224
};

// 蛇头结构体
struct Snake {
    int len;
    int headX;
    int headY;
};

// 蛇身结构体
struct Body {
    int bodyX;
    int bodyY;
};

// 函数声明
void HideCursor();
void CursorJump(int x, int y);
void InitMap();
void InitSnake();
void DrawMap();
void CreateFood();
void MoveSnake();
int GameOver();

#endif