/**
 * Created by LonelyEnvoy on 2017-4-3.
 * Jin Ge Jin Qu hao
 * Keywords: 多因素dp（用结构体构造dp数组）
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

struct Unit {
    int count;
    int elapsedTime;
};

Unit dp[51][9000];

Unit optimal(Unit a, Unit b) {
    if (a.count > b.count) {
        return a;
    }
    if (a.count < b.count) {
        return b;
    }
    if (a.elapsedTime > b.elapsedTime) {
        return a;
    }
    return b;
}

int main() {

    int T;
    int kase = 0;
    scanf("%d", &T);
    int numOfSongs;
    int avaTime;
    int times[51];
    while (T--) {
        memset(dp, 0, sizeof(dp));

        scanf("%d%d", &numOfSongs, &avaTime);
        erep(i, 1, numOfSongs) {
            scanf("%d", times + i);
        }

        Unit next;
        erep(i, 1, numOfSongs) {
            erep(j, 0, avaTime) {
                if (i == 1) {
                    dp[i][j].count = 0;
                    dp[i][j].elapsedTime = 0;
                } else {
                    dp[i][j] = dp[i-1][j];
                }

                if (j > times[i]) {
                    next = dp[i-1][j-times[i]];
                    next.count++;
                    next.elapsedTime += times[i];
                    dp[i][j] = optimal(dp[i][j], next);
                }
            }
        }

        Unit& result = dp[numOfSongs][avaTime];
        printf("Case %d: %d %d\n", ++kase, result.count + 1, result.elapsedTime + 678);
    }
    return 0;
}