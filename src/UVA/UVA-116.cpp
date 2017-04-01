/**
 * Created by LonelyEnvoy on 2017-4-2.
 * Unidirectional TSP
 * Keywords: dp
 */

 /*
 总结：
 1. dp 完毕遍历输出的时候，循着最小路径依次输出，注意对比的是 dp 数组而不是源输入数组，容易写错。
 2. 由于 INF 值可能涉及整数加减，故不能使用numeric_limits<int>::max()，否则可能溢出。建议使用0x3f3f3f3f，一般题设数据不会超出此范围。
 3. 在长时间调试依然 WA 时，为了不占用队友的上机时间，可以将输出流重定向到文件，打印出来再仔细比对。方法：
    FILE* fp = freopen("out.txt", "w", stdout);
    // ...
    // printf ...
    // ...
    fclose(fp); // 不可缺少，否则文件不会保存
 4. 不要使用过多的宏定义简写，容易出错，影响效率和调试体验。
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <limits>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define erep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 1000
// end of header

int m; // x
int n; // y

int matrix[MAX][MAX];
int dp[MAX][MAX];
int minWeight;

// calculate total min weight and select the best route
int solve(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = matrix[x][y];
    if (x >= 0 && x <= m-1 && y >= 0 && y <= n-2) { // stops when hit right bound
        int minNext = INF;
        int targetX;
        erep(i, -1, 1) {
            targetX = x + i;
            // 越界处理
            if (targetX == -1) {
                targetX = m - 1;
            } else if (targetX == m) {
                targetX = 0;
            }
            minNext = min(minNext, solve(targetX, y + 1) + matrix[x][y]);
        }
        dp[x][y] = minNext;
    }
    return dp[x][y];
}

// print the solution
void printPath() {
    // find the starting point
    int x; // starting point (x,0)
    int minW = INF;
    rep(i, 0, m) {
        if (dp[i][0] < minW) {
            minW = dp[i][0];
            x = i;
        }
    }

    vector<int> path;
    path.push_back(x);
    int targetX;
    int minTarget;
    int minX;
    int lastX = x;

    int traverseOrder[3]; // the order of searching

    rep(j, 1, n) {
        minTarget = INF;
        if (lastX == 0) { // make sure it's lexicographically ordered
            traverseOrder[0] = 0;
            traverseOrder[1] = 1;
            traverseOrder[2] = -1;
        } else if (lastX == m - 1) {
            traverseOrder[0] = 1;
            traverseOrder[1] = -1;
            traverseOrder[2] = 0;
        } else {
            traverseOrder[0] = -1;
            traverseOrder[1] = 0;
            traverseOrder[2] = 1;
        }
        rep(i, 0, 3) {
            targetX = lastX + traverseOrder[i];
            // 越界处理
            if (targetX == -1) {
                targetX = m - 1;
            } else if (targetX == m) {
                targetX = 0;
            }
            // log the min path
            if (dp[targetX][j] < minTarget) {
                minTarget = dp[targetX][j];
                minX = targetX;
            }
        }
        path.push_back(minX);
        lastX = minX;
    }

    // output
    bool first = true;
    rep(i, 0, n) {
        if (!first) {
            printf(" ");
        } else {
            first = false;
        }
        printf("%d", path[i] + 1);
    }
    printf("\n");
}

int main() {
    while (~scanf("%d%d", &m, &n)) {
        // init
        memset(dp, -1, sizeof(dp));
        minWeight = INF;
        // read
        rep(i, 0, m) {
            rep(j, 0, n) {
                scanf("%d", &matrix[i][j]);
            }
        }
        // parse
        rep(i, 0, m) {
            minWeight = min(minWeight, solve(i, 0));
        }
        // output
        printPath();
        printf("%d\n", minWeight);
    }
    return 0;
}
