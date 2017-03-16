/**
 * Created by LonelyEnvoy on 2017-3-17.
 * L3-004. 肿瘤诊断
 * Keywords: bfs，迷宫
 * Limits: High run-time efficiency required
 *         Do not use DFS in this problem, or you will encounter Segment fault! (Stack Overflow on OJ)
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_ROW 1287 // 切片分辨率最大行数
#define MAX_COLUMN 129 // 切片分辨率最大列数
#define MAX_LEVEL 61 // 切片最大层数
#define TUMOR 1 // 肿瘤像素
#define BLANK 0 // 正常像素

struct Coordinate {
    int x;
    int y;
    int z;
    Coordinate(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

const int positionDelta[3][6] = {
        // [i, j]
        // i: 0 -- x, 1 -- y, 2 -- z
        // j: 0 -- north, 1 -- east, 2 -- south, 3 -- west, 4 -- up, 5 -- down
        -1, 0, 1, 0, 0, 0,
        0, 1, 0, -1, 0, 0,
        0, 0, 0, 0, -1, 1
};

int graph[MAX_LEVEL][MAX_ROW][MAX_COLUMN]; // 肿瘤影像图，执行一次遍历后将变为全0
int row;
int column;
int level;
int minTumorUnitBoundary; // 忽略小于此阈值的肿瘤连通块
int sumTumorSize; // 肿瘤块总和

inline bool isCoordinateValid(Coordinate c) {
    return c.x >= 1 && c.x <= row && c.y >= 1 && c.y <= column && c.z >= 1 && c.z <= level;
}

inline bool isCoordinateTumor(Coordinate c) {
    return graph[c.z][c.x][c.y] == TUMOR;
}

void bfs(Coordinate start, int markingIndex) {
    queue<Coordinate> visitQueue;
    visitQueue.push(start);
    graph[start.z][start.x][start.y] = markingIndex;

    int tumorCount = 1;
    while (!visitQueue.empty()) {
        Coordinate curr = visitQueue.front();
        visitQueue.pop();

        // continue traversing
        for (int i = 0; i < 6; i++) {
            Coordinate next = Coordinate(curr.x + positionDelta[0][i],
                                         curr.y + positionDelta[1][i],
                                         curr.z + positionDelta[2][i]);
            if (isCoordinateValid(next) && isCoordinateTumor(next)) {
                // visit
                graph[next.z][next.x][next.y] = markingIndex;
                tumorCount++;
                visitQueue.push(next);
            }
        }
    }
    if (tumorCount >= minTumorUnitBoundary) {
        sumTumorSize += tumorCount;
    }
}

int main() {

    // init
    sumTumorSize = 0;

    // read
    scanf("%d%d%d%d", &row, &column, &level, &minTumorUnitBoundary);
    for (int k = 1; k <= level; k++) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                scanf("%d", &graph[k][i][j]);
            }
        }
    }

    // parse
    for (int k = 1; k <= level; k++) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= column; j++) {
                Coordinate curr(i, j, k);
                if (isCoordinateTumor(curr)) {
                    bfs(curr, 0);
                }
            }
        }
    }

    // output
    printf("%d\n", sumTumorSize);
}
