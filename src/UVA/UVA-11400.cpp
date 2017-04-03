/**
 * Created by LonelyEnvoy on 2017-4-3.
 * Lighting System Design
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

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 1001
// end of header

struct Unit {
    int v, k, c, l;
    bool operator<(const Unit& u) {
        return v < u.v;
    }
};

Unit units[MAX];
int sumNumOfBlub[MAX];
int dp[MAX];

int main() {
    int n;
    while (~scanf("%d", &n) && n) {

        memset(sumNumOfBlub, 0, sizeof(sumNumOfBlub));
        memset(dp, 0, sizeof(dp));

        erep(i, 1, n) {
            scanf("%d%d%d%d", &units[i].v, &units[i].k, &units[i].c, &units[i].l);
        }
        sort(units + 1, units + n + 1);

        erep(i, 1, n) {
            dp[i] = dp[i - 1] + units[i].c * units[i].l + units[i].k;
        }

        erep(i, 1, n) {
            erep(j, 1, i) {
                sumNumOfBlub[i] += units[j].l;
            }
        }

        erep(i, 1, n) {
            erep(j, 0, i) {
                dp[i] = min(dp[i], dp[j] + (sumNumOfBlub[i] - sumNumOfBlub[j]) * units[i].c + units[i].k);
            }
        }

        printf("%d\n", dp[n]);
    }
    return 0;
}
