/**
 * Created by LonelyEnvoy on 2017-4-4.
 * Partitioning by Palindromes
 * Keywords: dp
 */

// 状态定义：第 i 个字母前（包括此字母）共有 dp[i] 个回文串
// 状态转移方程：dp[i] = min { dp[j] + 1 | j <= i-1, str[j+1...i] 是回文串 }

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <limits>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; ++i)
#define erep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, a, n) for (int i = n - 1; i >= a; --i)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 1001

char str[MAX];
bool palin[MAX][MAX]; // palin[i][j] 记录第 i 个字母到第 j 个字母组成的子串是否为回文串
int dp[MAX];

bool isPalin(int a, int b) { // 判断第 i 个字母到第 j 个字母组成的子串是否为回文串
    if (a == b) {
        return true;
    }
    int mid = (a + b) / 2;
    if ((b - a) % 2) { // len is even
        erep(i, 0, mid - a) {
            if (str[mid-i] != str[mid+i+1]) {
                return false;
            }
        }
    } else { // len is odd
        erep(i, 1, mid - a) {
            if (str[mid-i] != str[mid+i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(palin, false, sizeof(palin));
        memset(dp, 0, sizeof(dp));

        scanf("%s", str + 1);
        int len = 0;
        while (str[len + 1] != '\0') len++;

        erep(i, 1, len) {
            erep(j, 1, i) {
                palin[j][i] = isPalin(j, i);
            }
        }

        int mindp;
        erep(i, 1, len) {
            mindp = INF;
            erep(j, 0, i-1) { // 注意！必须从0开始，因为 dp[1] = dp[0] + 1。如果从1开始，会导致dp[1] = 0（第1个字母自身不是回文串，错误）
                if (palin[j+1][i] && dp[j] + 1 < mindp) {
                    mindp = dp[j] + 1;
                }
            }
            dp[i] = mindp == INF ? 0 : mindp;
        }

        printf("%d\n", dp[len]);
    }
}
