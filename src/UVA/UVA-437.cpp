/**
 * Created by LonelyEnvoy on 2017-4-1.
 * The Tower of Babylon
 * Keywords: dp
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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 1000
// end of header

struct Block {
    int x;
    int y;
    int z;
};

Block b[MAX]; // blocks
bool g[MAX][MAX]; // 邻接矩阵
int dp[MAX]; // block的下标对应的状态（累积最高高度）
int n;

bool isStackable(int i, int j) { // whether i can be placed under j
    return (b[i].x > b[j].x && b[i].y > b[j].y) || (b[i].x > b[j].y && b[i].y > b[j].x);
}

int maxHeight(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = b[u].z;
    rep(i, 0, n) {
        if (g[u][i]) {
            dp[u] = max(dp[u], maxHeight(i) + b[u].z);
        }
    }
    return dp[u];
}

int main() {

    int kase = 0;
    while (~scanf("%d", &n) && n) {

        memset(g, false, sizeof(g));
        memset(dp, -1, sizeof(dp));

        rep(i, 0, n) {
            scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
        }
        rep(i, 0, n) {
            b[n + i].x = b[i].y;
            b[n + i].y = b[i].z;
            b[n + i].z = b[i].x;
            b[2 * n + i].x = b[i].z;
            b[2 * n + i].y = b[i].x;
            b[2 * n + i].z = b[i].y;
        }
        n *= 3;

        rep(i, 0, n) {
            rep(j, i + 1, n) {
                g[i][j] = isStackable(i, j);
                g[j][i] = isStackable(j, i);
            }
        }

        int height = 0;
        rep(i, 0, n) {
            height = max(height, maxHeight(i));
        }

        printf("Case %d: maximum height = %d\n", ++kase, height);
    }
    return 0;
}
