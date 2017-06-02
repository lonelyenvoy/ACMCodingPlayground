/**
 * Created by LonelyEnvoy on 2017-6-2.
 * Frogger
 * Keywords: 最短路径，dp，floyd/dijkstra/spfa
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 201

double g[MAX][MAX];
int posx[MAX];
int posy[MAX];
int n;

void floyd() {
    double (&dp)[MAX][MAX] = g;
    rep(k,0,n)
        rep(i,0,n)
            rep(j,0,n) {
                dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
            }
}

int main() {
    int kase = 0;
    while (~scanf("%d", &n) && n) {
        rep(i,0,n) {
            scanf("%d%d", posx+i, posy+i);
        }
        rep(i,0,n) {
            rep(j,0,n) {
                g[i][j] = sqrt((double)((posx[i] - posx[j]) * (posx[i] - posx[j])
                        + (posy[i] - posy[j]) * (posy[i] - posy[j])));
            }
        }
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++kase, g[0][1]);
    }
}


