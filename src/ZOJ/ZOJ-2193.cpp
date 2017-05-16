/**
 * Created by LonelyEnvoy on 2017-5-16
 * Broken windows
 * Keywords: dfs, 拓扑排序
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
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

#define rep(i,a,n) for (int i = a; i < n; i++)
#define erep(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n-1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

bool g[10][10];

void read() {
    int a;
    // (1,1) 1
    scanf("%d", &a);
    // (1,2) 1 2
    scanf("%d", &a);
    if (a == 1) g[1][2] = true;
    else if (a == 2) g[2][1] = true;
    // (1,3) 2 3
    scanf("%d", &a);
    if (a == 2) g[2][3] = true;
    else if (a == 3) g[3][2] = true;
    // (1,4) 3
    scanf("%d", &a);

    // (2,1) 1 4
    scanf("%d", &a);
    if (a == 1) g[1][4] = true;
    else if (a == 4) g[4][1] = true;
    // (2,2) 1 2 4 5
    scanf("%d", &a);
    if (a == 1) g[1][2] = g[1][4] = g[1][5] = true;
    else if (a == 2) g[2][1] = g[2][4] = g[2][5] = true;
    else if (a == 4) g[4][1] = g[4][2] = g[4][5] = true;
    else if (a == 5) g[5][1] = g[5][2] = g[5][4] = true;
    // (2,3) 2 3 5 6
    scanf("%d", &a);
    if (a == 2) g[2][3] = g[2][5] = g[2][6] = true;
    else if (a == 3) g[3][2] = g[3][5] = g[3][6] = true;
    else if (a == 5) g[5][2] = g[5][3] = g[5][6] = true;
    else if (a == 6) g[6][2] = g[6][3] = g[6][5] = true;
    // (2,4) 3 6
    scanf("%d", &a);
    if (a == 3) g[3][6] = true;
    else if (a == 6) g[6][3] = true;

    // (3,1) 4 7
    scanf("%d", &a);
    if (a == 4) g[4][7] = true;
    else if (a == 7) g[7][4] = true;
    // (3,2) 4 5 7 8
    scanf("%d", &a);
    if (a == 4) g[4][5] = g[4][7] = g[4][8] = true;
    else if (a == 5) g[5][4] = g[5][7] = g[5][8] = true;
    else if (a == 7) g[7][4] = g[7][5] = g[7][8] = true;
    else if (a == 8) g[8][4] = g[8][5] = g[8][7] = true;
    // (3,3) 5 6 8 9
    scanf("%d", &a);
    if (a == 5) g[5][6] = g[5][8] = g[5][9] = true;
    else if (a == 6) g[6][5] = g[6][8] = g[6][9] = true;
    else if (a == 8) g[8][5] = g[8][6] = g[8][9] = true;
    else if (a == 9) g[9][5] = g[9][6] = g[9][8] = true;
    // (3,4) 6 9
    scanf("%d", &a);
    if (a == 6) g[6][9] = true;
    else if (a == 9) g[9][6] = true;

    // (4,1) 7
    scanf("%d", &a);
    // (4,2) 7 8
    scanf("%d", &a);
    if (a == 7) g[7][8] = true;
    else if (a == 8) g[8][7] = true;
    // (4,3) 8 9
    scanf("%d", &a);
    if (a == 8) g[8][9] = true;
    else if (a == 9) g[9][8] = true;
    // (4,4) 9
    scanf("%d", &a);

    // read END
    char buffer[4];
    scanf("%s", buffer);
}

int visit[10];

bool dfs(int u) {
    visit[u] = -1;
    erep(v,1,9) {
        if (g[u][v]) {
            if (visit[v] == -1) return false;
            if (visit[v] == 0 && !dfs(v)) return false;
        }
    }
    visit[u] = 1;
    return true;
}

bool toposort() {
    memset(visit, 0, sizeof(visit));
    erep(u,1,9) {
        if (g[u] && visit[u] == 0 && !dfs(u)) return false;
    }
    return true;
}

int main() {
    char buffer[12];
    while (~scanf("%s", buffer) && strlen(buffer) == 5) {
        memset(g, 0, sizeof(g));
        read();
        if (toposort()) {
            printf("THESE WINDOWS ARE CLEAN\n");
        } else {
            printf("THESE WINDOWS ARE BROKEN\n");
        }
    }
}