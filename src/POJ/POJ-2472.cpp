/**
 * Created by LonelyEnvoy on 2017-5-27.
 * 106 miles to Chicago
 * Keywords: shortest path, dijkstra
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n - 1; i >= a; --i)

const int INF = 0x3f3f3f3f;

#define MAX 1000

double g[MAX][MAX];
bool vis[MAX];
double dis[MAX];
int n;

double dij() {
    memset(vis, false, sizeof(vis)); 
    rep(i,0,n) {
        dis[i] = g[0][i];
    }
    vis[0] = true;
    
    double cur;
    double best;
    int k;
    rep(i,1,n) {
        best = -1;
        rep(j,0,n) {
            if (!vis[j] && dis[j] > best) {
                best = dis[j];
                k = j;
            }
        }
        vis[k] = true;
        rep(j,0,n) {
            if (!vis[j] && (cur = g[k][j] * best) > dis[j]) {
               dis[j] = cur;
            }
        }
    }
    return dis[n-1];
}

void print() {
    rep(i,0,n) {
        printf("%f ", dis[i]);
    }
    printf("\n");
}

int main() {

    int m;
    int a, b, v;
    while (~scanf("%d", &n) && n) {
        memset(g, 0, sizeof(g));
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &a, &b, &v);
            g[a-1][b-1] = g[b-1][a-1] = (double)v / 100;
        }
        rep(i,0,n) {
            g[i][i] = 1;
        }
        printf("%.6f percent\n", dij() * 100);
    }
}

