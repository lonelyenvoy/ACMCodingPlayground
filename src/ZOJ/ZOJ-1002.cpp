/**
 * Created by LonelyEnvoy on 2017-3-24.
 * Fire Net
 * Keywords: dfs/bfs，迷宫（暴力搜索）
 */

#include <cstdio>
using namespace std;

#define MAX 4

char maze[MAX + 2][MAX + 2];
int n;
int houses;
int maxHouses;

void init() {
    for (int i = 0; i <= n; i++) {
        maze[0][i] = 'X';
        maze[i][0] = 'X';
        maze[n][i] = 'X';
        maze[i][n] = 'X';
    }
    houses = 0;
    maxHouses = 0;
}

bool check(int x, int y) {
    if (maze[x][y] != '.') {
        return false;
    }

    int houseY = -1;
    for (int i = 1; i < y; i++) {
        if (maze[x][i] == '@') {
            houseY = i;
        }
    }
    int wallY = -1;
    for (int i = n; i >= 1; i--) {
        if (maze[x][i] == 'X') {
            wallY = i;
        }
    }
    if (houseY != -1 && wallY < houseY) {
        return false;
    }

    int houseX = -1;
    for (int i = 1; i < x; i++) {
        if (maze[i][y] == '@') {
            houseX = i;
        }
    }
    int wallX = -1;
    for (int i = n; i >= 1; i--) {
        if (maze[i][y] == 'X') {
            wallX = i;
        }
    }
    if (houseX != -1 && wallX < houseX) {
        return false;
    }
    return true;
}

void dfs(int x, int y, int count) {
    int nextX = x;
    int nextY = y + 1;
    if (y % n == 0) { // new row
        nextX++;
        nextY = 1;
    }
    if (x >= 1 && x <= n && y >= 1 && y <= n) {
        if (check(x, y)) {
            maze[x][y] = '@';
            houses++;
            if (houses > maxHouses) {
                maxHouses = houses;
            }
            dfs(nextX, nextY, count + 1);
            houses--;
            maze[x][y] = '.';
        }
        // try not to place the house even when possible
        // 避免陷入局部最优
        dfs(nextX, nextY, count);
    }
}

int main() {
    while (scanf("%d", &n) == 1 && n != 0) {
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '\n' || maze[i][j] == '\r') {
                    j--;
                    continue;
                }
            }
        }

        dfs(1, 1, 0);

        printf("%d\n", maxHouses);
    }
    return 0;
}