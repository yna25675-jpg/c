#include "snake.h.h"

//蛇头
struct Snake snake;

//蛇身
struct Body body[ROW * COL]; //开辟存储蛇身的结构体

//地图
int map[ROW][COL];      //标记各个位置的状态

int score = 0 ;
int direction = RIGHT;
int foodX ,foodY;


//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO curInfo;
    curInfo.dwSize = 1;
    curInfo.bVisible = FALSE;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &curInfo);
}

//光标跳转
void CursorJump(int x,int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { y * 2, x };
    SetConsoleCursorPosition(handle, pos);
}
//颜色设置

//初始化界面
void InitMap()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
                map[i][j] = WALL;
            else
                map[i][j] = EMPTY;
        }
    }
}

//初始化蛇
void InitSnake()
{
    snake.len = 3;
    snake.headX = ROW / 2;
    snake.headY = COL / 2;

    for (int i = 0; i < snake.len; i++)
    {
        body[i].bodyX = snake.headX;
        body[i].bodyY = snake.headY - i;
        map[body[i].bodyX][body[i].bodyY] = (i == 0) ? HEAD : BODY;
    }
}

//随机生成食物
void CreateFood()
{
     while (1)
    {
        int x = rand() % (ROW - 2) + 1;
        int y = rand() % (COL - 2) + 1;
        if (map[x][y] == EMPTY)
        {
            map[x][y] = FOOD;
            foodX = x;
            foodY = y;
            break;
        }
    }
}

//打印地图
void DrawMap()
{
    CursorJump(0, 0);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            switch (map[i][j])
            {
                case WALL: printf("■"); break;
                case HEAD: printf("●"); break;
                case BODY: printf("○"); break;
                case FOOD: printf("★"); break;
                default:   printf("  "); break;
            }
        }
        printf("\n");
    }
    printf("得分：%d\n", score);
}
// 移动蛇
void MoveSnake()
{
    int newX = snake.headX;
    int newY = snake.headY;

    if (_kbhit())
    {
        int key = _getch();
        if (key == ARROW)
        {
            key = _getch();
            if ((key == UP && direction != DOWN) ||
                (key == DOWN && direction != UP) ||
                (key == LEFT && direction != RIGHT) ||
                (key == RIGHT && direction != LEFT))
            {
                direction = key;
            }
        }
    }

    switch (direction)
    {
        case UP: newX--; break;
        case DOWN: newX++; break;
        case LEFT: newY--; break;
        case RIGHT: newY++; break;
    }

    // 撞墙或撞自己
    if (map[newX][newY] == WALL || map[newX][newY] == BODY)
    {
        system("cls");
        printf("游戏结束！最终得分：%d\n", score);
        exit(0);
    }

    // 吃食物
    int eat = (map[newX][newY] == FOOD);
    if (eat)
    {
        score += 10;
        snake.len++;
        CreateFood();
    }
    // 在移动前保存尾巴
    int tailX = body[snake.len - 1].bodyX;
    int tailY = body[snake.len - 1].bodyY;

    // 移动身体
    for (int i = snake.len - 1; i > 0; i--)
    {
        body[i] = body[i - 1];
        map[body[i].bodyX][body[i].bodyY] = BODY;
    }

    // 更新蛇头
    snake.headX = newX;
    snake.headY = newY;
    body[0].bodyX = newX;
    body[0].bodyY = newY;
    map[newX][newY] = HEAD;

    // 清理尾巴
    if (!eat)
    {
        map[tailX][tailY] = EMPTY;
    }
}

// 主逻辑
int main()
{
	srand((unsigned)time(NULL));
    HideCursor();
    InitMap();
    InitSnake();
    CreateFood();

    while (1)
    {
        DrawMap();
        MoveSnake();
        Sleep(150);
    }

    return 0;
}