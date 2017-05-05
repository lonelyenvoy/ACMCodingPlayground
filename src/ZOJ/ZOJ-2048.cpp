/**
 * Created by LonelyEnvoy on 2017-5-5.
 * Highways
 * Keywords: 图论，最小生成树（Kruskal/Prim），并查集
 * See: ZOJ 1203
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

#define MAXN 751
#define MAXM 1001

struct Cord {
    int x,y;
};

struct Edge {
    int u,v;
    double w;

    bool operator<(const Edge& e) const {
        return this->w > e.w;
    }
};

Cord cords[MAXN];
priority_queue<Edge> edges;
int n;
int m;

int ufsets[MAXN];

inline void init() {
    memset(ufsets, -1, sizeof(ufsets));
    while (!edges.empty()) {
        edges.pop();
    }
}

int find(int u) {
    if (ufsets[u] < 0) return u;
    return ufsets[u] = find(ufsets[u]);
}

bool join(int u1, int u2) {
    u1 = find(u1);
    u2 = find(u2);
    if (u1 == u2) return false;
    if (ufsets[u1] <= ufsets[u2]) { // u1 is larger
        ufsets[u1] += ufsets[u2];
        ufsets[u2] = u1;
    } else {
        ufsets[u2] += ufsets[u1];
        ufsets[u1] = u2;
    }
    return true;
}

int numOfSets() {
    int count = 0;
    erep(i,1,n) {
        if (ufsets[i] < 0) {
            count++;
        }
    }
    return count;
}

void kruskal() {
    Edge e;
    while (numOfSets() > 1) {
        e = edges.top();
        edges.pop();
        if (find(e.u) == find(e.v)) continue;
        join(e.u, e.v);
        printf("%d %d\n", e.u, e.v);
    }
}

int main() {
    int kase;
    Edge e;
    int city1, city2;

    scanf("%d", &kase);
    rep(k,0,kase) {
        init();
        scanf("%d", &n);
        rep(i,0,n) {
            scanf("%d%d", &cords[i].x, &cords[i].y);
        }
        rep(i,0,n) {
            rep(j,i+1,n) {
                e.u = i + 1;
                e.v = j + 1;
                e.w = sqrt(
                           (cords[i].x - cords[j].x) * (cords[i].x - cords[j].x)
                           + (cords[i].y - cords[j].y) * (cords[i].y - cords[j].y)
                           );
                // debug
                //printf("dis %d : %d = %lf\n", e.u, e.v, e.w);
                edges.push(e);
            }
        }
        scanf("%d", &m);
        rep(i,0,m) {
            scanf("%d%d", &city1, &city2);
            join(city1, city2);
        }
        if (k > 0) {
            printf("\n");
        }
        kruskal();
    }
}



