/**
 * Created by LonelyEnvoy on 2017-3-14.
 * N皇后问题
 * Keywords: dfs，回溯法
 * Limits: High run-time efficiency required
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 11

bool columnOccupied[MAX]; // 已被其他皇后占用的列
bool mainDiagonalOccupied[MAX * 2]; // 已被其他皇后占用的主对角线
bool subDiagonalOccupied[MAX * 2]; // 已被其他皇后占用的副对角线
int solutionCount;
int n;

int resultMap[MAX]; // 打表

void search(int curr) {
    if (curr == n) { // all chess placed -- got a solution
        solutionCount++;
        return;
    }
    for (int i = 0; i < n; i++) { // loop to search for all possible solutions
        // recurse only when the place is not occupied
        if (!columnOccupied[i] && !mainDiagonalOccupied[curr - i + n] && !subDiagonalOccupied[curr + i]) {
            columnOccupied[i] = mainDiagonalOccupied[curr - i + n] = subDiagonalOccupied[curr + i] = true;
            search(curr + 1);
            columnOccupied[i] = mainDiagonalOccupied[curr - i + n] = subDiagonalOccupied[curr + i] = false;
        }
    }
}

int main() {
    memset(resultMap, -1, sizeof(int) * MAX);

    while (true) {
        // init
        memset(columnOccupied, 0, sizeof(bool) * MAX);
        memset(mainDiagonalOccupied, 0, sizeof(bool) * MAX * 2);
        memset(subDiagonalOccupied, 0, sizeof(bool) * MAX * 2);
        solutionCount = 0;

        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if (resultMap[n] != -1) {
            printf("%d\n", resultMap[n]);
            continue;
        }
        search(0);
        resultMap[n] = solutionCount;
        printf("%d\n", solutionCount);
    }
    return 0;
}