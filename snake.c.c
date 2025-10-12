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
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 获取控制台句柄
    CursorJump(0, 0);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            switch (map[i][j])
            {
                case WALL:
                    SetConsoleTextAttribute(handle, COLOR_BLUE);
                    printf("■");
                    break;
                case HEAD:
                    SetConsoleTextAttribute(handle, COLOR_RED);
                    printf("●");
                    break;
                case BODY:
                    SetConsoleTextAttribute(handle, COLOR_LIGHT_BLUE);
                    printf("○");
                    break;
                case FOOD:
                    SetConsoleTextAttribute(handle, COLOR_WHITE);
                    printf("★");
                    break;
                default:
                    SetConsoleTextAttribute(handle, COLOR_DEFAULT);
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }

    // 打印分数
    SetConsoleTextAttribute(handle, COLOR_WHITE);
    printf("得分：%d\n", score);

    // 恢复默认颜色
    SetConsoleTextAttribute(handle, COLOR_DEFAULT);
}
// 移动蛇
void MoveSnake()
{
    int newX = snake.headX;
    int newY = snake.headY;

    if (_kbhit())
    {
        int key = _getch();

        // 方向键
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
        // ✅ 暂停功能放这里
        else if (key == SPACE)
        {
            CursorJump(ROW + 2, 0);  // 在地图下方输出提示
            printf("暂停中，按任意键继续...");
            _getch(); // 等待玩家按任意键
            CursorJump(ROW + 2, 0);
            printf("                      "); // 清空提示文字
        }
    }

    // ↓↓↓ 下面是蛇移动逻辑
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

    // 移动身体
    int tailX = body[snake.len - 1].bodyX;
    int tailY = body[snake.len - 1].bodyY;

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