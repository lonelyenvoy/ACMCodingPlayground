/**
 * Created by LonelyEnvoy on 2017-3-16.
 * Knight Moves
 * Keywords: bfs，迷宫，最短路径
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Coordinate { // simple struct of [x, y]
    int x;
    int y;
    Coordinate(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    bool operator==(const Coordinate& o) {
        return this->x == o.x && this->y == o.y;
    }

    bool operator!=(const Coordinate& o) {
        return !(*this == o);
    }
};

bool visited[9][9]; // log whether a position on chessboard has been visited
const int positionDelta[2][8] = { // the offset to move in 8 directions
        // [i][j]
        // i
        // 0 -- x, 1 -- y
        // j
        // 0 -- 北偏东，1 -- 东偏北，2 -- 东偏南，3 -- 南偏东，
        // 4 -- 南偏西，5 -- 西偏南，6 -- 西偏北，7 -- 北偏西
        -2, -1, 1, 2, 2, 1, -2, -1,
        1, 2, 2, 1, -1, -2, -1, -2
};

Coordinate lastPosition[9][9]; // 记录bfs移动过程中移到棋盘上每一个点之前的上一个点的坐标
Coordinate startPosition; // where the knight was at the beginning
Coordinate targetPosition; // where thr knight is heading for

// judge if a position is inside the chessboard and not already visited
bool isCoordinateValid(Coordinate c) {
    return c.x >= 1 && c.x <= 8 && c.y >= 1 && c.y <= 8 && !visited[c.x][c.y];
}

void bfs(Coordinate start) {
    queue<Coordinate> visitQueue;
    visitQueue.push(start);

    while (!visitQueue.empty()) {
        Coordinate curr = visitQueue.front();
        visitQueue.pop();

        // visit
        visited[curr.x][curr.y] = true;
        if (curr == targetPosition) { // reach target position
            return;
        }

        // continue traversing
        for (int i = 0; i < 8; i++) {
            Coordinate next = Coordinate(curr.x + positionDelta[0][i], curr.y + positionDelta[1][i]);
            if (isCoordinateValid(next)) { // if the next position is valid, go on
                visitQueue.push(next);
                lastPosition[next.x][next.y] = curr;
            }
        }
    }
}

int countMoves() { // count how many steps the knight has moved
    Coordinate curr = targetPosition; // starting from the fianl position

    int step = 0;
    while (curr != startPosition) {
        curr = lastPosition[curr.x][curr.y];
        step++;
    }
    return step;
}

int main() {
    char first[3];
    char second[3];
    while (scanf("%s%s", first, second) == 2) {

        // init
        memset(visited, false, sizeof(bool) * 9 * 9);

        // read
        startPosition = Coordinate(first[1] - '0', first[0] - 'a' + 1);
        targetPosition = Coordinate(second[1] - '0', second[0] - 'a' + 1);

        // parse
        bfs(startPosition);

        // output
        printf("To get from %s to %s takes %d knight moves.\n", first, second, countMoves());
    }
}
