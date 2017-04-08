/**
 * Created by LonelyEnvoy on 2017-4-8.
 * The Suspects
 * Keywords: 并查集，水题
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

#define MAX 30001

int ufset[MAX];

void init() {
    memset(ufset, -1, sizeof(ufset));
}

int find(int u) {
    int r = u;
    while (ufset[r] >= 0) {
        r = ufset[r];
    }
    int t;
    while (u != r) {
        t = ufset[u];
        ufset[u] = r;
        u = t;
    }
    return r;
}

bool join(int u1, int u2) {
    u1 = find(u1);
    u2 = find(u2);
    if (u1 == u2) return false;
    ufset[u1] += ufset[u2];
    ufset[u2] = u1;
    return true;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
        init();
        int num;
        int cur;
        int first;
        rep(i, 0, m) {
            scanf("%d", &num);
            scanf("%d", &first);
            rep(j, 1, num) {
                scanf("%d", &cur);
                join(first, cur);
            }
        }
        printf("%d\n", -ufset[find(0)]);
    }
}
