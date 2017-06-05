/**
 * Created by LonelyEnvoy on 2017-6-4.
 * Burn the Linked Camp
 * Keywords: 差分约束系统，最短路径
 */

// 参考资料：http://www.cnblogs.com/-sunshine/archive/2013/02/27/2935824.html

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int INF = 0x3f3f3f3f;

#define MAX 30000

struct Edge {
    int u, v, w;
};

Edge edges[MAX];
int c[MAX];
int d[MAX];
int n;
int m;

int dis[MAX];

void debug() {
    rep(i,0,n) {
    if (dis[i] > INF * 0.5) printf("- ");
        else printf("%d ", dis[i]);
    }
    printf("\n");
}

bool bellman() {
    rep(i,1,n) {
        dis[i] = INF;
    }
    dis[0] = 0;

    Edge e;
    rep(k,0,n) {
        rep(i,0,m) {
            e = edges[i];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
            }
        }
    }

    rep(i,0,m) {
        e = edges[i];
        if (dis[e.u] + e.w < dis[e.v]) {
            return false;
        }
    }
    return true;
}

inline void init() {
    m = 0;
    d[0] = 0;
}

void addEdge(int u, int v, int w) {
    edges[m].u = u;
    edges[m].v = v;
    edges[m].w = w;
    m++;
}

int main() {
    int k;
    int u, v, w;
    while (~scanf("%d%d", &n, &k)) {
        init();
        erep(i,1,n) {
            scanf("%d", c+i);
            addEdge(i-1, i, c[i]);
            addEdge(i, i-1, 0);
            d[i] = d[i-1] + c[i];
        }
        rep(i,0,k) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(v, u-1, -w);
            addEdge(u-1, v, d[v] - d[u-1]);
        }
        if (!bellman()) {
            printf("Bad Estimations\n");
            continue;
        }
        printf("%d\n", dis[n] - dis[0]);
    }
}



