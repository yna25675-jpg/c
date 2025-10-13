#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUMAN 'X'   // 玩家符号
#define AI    'O'   // 电脑符号

// -------------------- 工具函数 --------------------

// 初始化棋盘：把每格编号为1~9
void initBoard(char b[9]) {
    for (int i = 0; i < 9; ++i)
        b[i] = '1' + i;
}

// 打印棋盘
void printBoard(const char b[9]) {
    printf("\n");
    printf(" %c | %c | %c \n", b[0], b[1], b[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", b[3], b[4], b[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n\n", b[6], b[7], b[8]);
}

// 判断某格是否为空
int isCellEmpty(const char b[9], int idx) {
    return b[idx] != 'X' && b[idx] != 'O';
}

// 是否还有空格（用于判断平局）
int movesLeft(const char b[9]) {
    for (int i = 0; i < 9; ++i)
        if (isCellEmpty(b, i)) return 1;
    return 0;
}

// 判断胜负：返回 'X'/'O'/'D'(平局)/'N'(未结束)
char getResult(const char b[9]) {
    int winLines[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (int i = 0; i < 8; ++i) {
        int a = winLines[i][0], c = winLines[i][1], d = winLines[i][2];
        if (b[a] == b[c] && b[c] == b[d])
            return b[a];
    }
    if (!movesLeft(b)) return 'D';
    return 'N';
}

// 读取安全整数
int readInt() {
    int x;
    while (scanf("%d", &x) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("输入无效，请重新输入数字：");
    }
    return x;
}

// -------------------- Minimax算法 --------------------

// 计算AI分数（赢高分，输低分）
int scoreOf(char res, char ai, char human, int depth) {
    if (res == ai) return 10 - depth;
    if (res == human) return depth - 10;
    return 0;
}

// 递归搜索最优解
int minimax(char b[9], int depth, int isMax, char ai, char human) {
    char res = getResult(b);
    if (res != 'N') return scoreOf(res, ai, human, depth);

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 9; ++i)
            if (isCellEmpty(b, i)) {
                char old = b[i];
                b[i] = ai;
                int val = minimax(b, depth + 1, 0, ai, human);
                b[i] = old;
                if (val > best) best = val;
            }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; ++i)
            if (isCellEmpty(b, i)) {
                char old = b[i];
                b[i] = human;
                int val = minimax(b, depth + 1, 1, ai, human);
                b[i] = old;
                if (val < best) best = val;
            }
        return best;
    }
}

// AI选择最佳落子位置
int bestMove(char b[9], char ai, char human) {
    int bestVal = -1000, bestIdx = -1;
    for (int i = 0; i < 9; ++i)
        if (isCellEmpty(b, i)) {
            char old = b[i];
            b[i] = ai;
            int val = minimax(b, 0, 0, ai, human);
            b[i] = old;
            if (val > bestVal) {
                bestVal = val;
                bestIdx = i;
            }
        }
    return bestIdx;
}

// -------------------- 游戏流程 --------------------

// 玩家下子
void humanTurn(char b[9], char who) {
    int pos;
    while (1) {
        printf("玩家 [%c]，请输入要落子的格子编号 (1-9)：", who);
        pos = readInt();
        if (pos < 1 || pos > 9) {
            printf("范围应为 1~9，请重试。\n");
            continue;
        }
        if (!isCellEmpty(b, pos - 1)) {
            printf("该位置已被占用，请选择其他位置。\n");
            continue;
        }
        b[pos - 1] = who;
        break;
    }
}

// 玩家 vs 玩家
void pvp() {
    char b[9];
    initBoard(b);
    char turn = 'X';
    while (1) {
        printBoard(b);
        humanTurn(b, turn);
        char res = getResult(b);
        if (res == 'X' || res == 'O') {
            printBoard(b);
            printf("玩家 [%c] 获胜！\n", res);
            break;
        } else if (res == 'D') {
            printBoard(b);
            printf("平局！\n");
            break;
        }
        turn = (turn == 'X') ? 'O' : 'X';
    }
}

// 玩家 vs AI
void pvc() {
    char b[9];
    initBoard(b);
    int choice;
    char human = HUMAN, ai = AI;

    printf("选择先手：1) 玩家先手[X]  2) 电脑先手[O] ：");
    choice = readInt();
    if (choice == 2) { human = AI; ai = HUMAN; }

    while (1) {
        printBoard(b);
        if (human == 'X') {
            // 玩家先手
            humanTurn(b, human);
            char res = getResult(b);
            if (res != 'N') { printBoard(b); if(res=='D') printf("平局！\n"); else printf("玩家胜利！\n"); break; }

            int aiIdx = bestMove(b, ai, human);
            b[aiIdx] = ai;
            printf("电脑 [%c] 下在了 %d。\n", ai, aiIdx + 1);
            res = getResult(b);
            if (res != 'N') { printBoard(b); if(res=='D') printf("平局！\n"); else printf("电脑胜利！\n"); break; }
        } else {
            // 电脑先手
            int aiIdx = bestMove(b, ai, human);
            b[aiIdx] = ai;
            printf("电脑 [%c] 下在了 %d。\n", ai, aiIdx + 1);
            char res = getResult(b);
            if (res != 'N') { printBoard(b); if(res=='D') printf("平局！\n"); else printf("电脑胜利！\n"); break; }

            printBoard(b);
            humanTurn(b, human);
            res = getResult(b);
            if (res != 'N') { printBoard(b); if(res=='D') printf("平局！\n"); else printf("玩家胜利！\n"); break; }
        }
    }
}

// -------------------- 主程序入口 --------------------
int main(void) {
    while (1) {
        printf("======= 井字棋 =======\n");
        printf("1) 玩家 vs 玩家\n");
        printf("2) 玩家 vs 电脑（最强AI）\n");
        printf("3) 退出\n");
        printf("请选择：");

        int op = readInt();
        if (op == 1) pvp();
        else if (op == 2) pvc();
        else if (op == 3) { printf("再见！\n"); break; }
        else { printf("无效选项，请重试。\n"); continue; }

        printf("\n再来一局吗？1) 是  2) 否 ：");
        int again = readInt();
        if (again != 1) { printf("感谢游玩！\n"); break; }
    }
    return 0;
}
