/**
 * Created by LonelyEnvoy on 2017-4-6.
 * Friendship
 * Keywords: 并查集
 */

// 注意并查集容易写错的地方，WA了很多次

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

#define MAX 100001

int ufsets[MAX];

void init() {
    memset(ufsets, -1, sizeof(ufsets));
}

int find(int u) {
    while (ufsets[u] >= 0) {
        u = ufsets[u];
    }
    return u;
}

bool setUnion(int s1, int s2) {
    s1 = find(s1);
    s2 = find(s2);
    if (s1 == s2) return false;
    if (ufsets[s1] < ufsets[s2]) { // s1's size is bigger than s2, let s1 be root
        ufsets[s1] += ufsets[s2]; // 注意：这里很容易写错！不能写成 ufsets[s1]-- 或者 ufsets[s1] -= ufsets[s2] ！
        ufsets[s2] = s1;
    } else {
        ufsets[s2] += ufsets[s1];
        ufsets[s1] = s2;
    }
    return true;
}

int main() {
    int n, m;
    char op;
    int p1, p2;
    int kase = 0;
    bool first = true;
    while (~scanf("%d%d", &n, &m) && n && m) {
        init();
        if (!first) {
            printf("\n");
        } else {
            first = false;
        }
        printf("Case %d:\n", ++kase);
        while (m--) {
            getchar();
            scanf("%c", &op);
            if (op == 'M') {
                scanf("%d%d", &p1, &p2);
                setUnion(p1, p2);
            } else {
                scanf("%d", &p1);
                printf("%d\n", -ufsets[find(p1)]);
            }
        }
    }
}
