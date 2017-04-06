/**
 * Created by LonelyEnvoy on 2017-4-6.
 * A. Boredom
 * Keywords: dp
 */

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

#define MAX 100005

int c[MAX]; // count of numbers
ll dp[MAX];

int main() {
    int n;
    int maxData = 0;
    int minData = INF;

    memset(dp, 0, sizeof(dp));

    scanf("%d", &n);
    int data;
    rep(i, 0, n) {
        scanf("%d", &data);
        if (data > maxData) {
            maxData = data;
        }
        if (data < minData) {
            minData = data;
        }
        c[data]++;
    }

    for (int i = minData; i <= maxData; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + (ll)c[i] * i);
    }

    printf("%I64d\n", dp[maxData]);
}
