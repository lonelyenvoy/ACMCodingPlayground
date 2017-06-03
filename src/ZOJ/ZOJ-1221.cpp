#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int INF = 0x3f3f3f3f;

#define N 20

int g[N][N];

void init() {
    rep(i,0,N)
        rep(j,0,N)
            if (i == j) 
                g[i][j] = 0;
            else
                g[i][j] = INF;
}

void floyd() {
    int (&dp)[N][N] = g;
    rep(k,0,N)
        rep(i,0,N)
            rep(j,0,N)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

void debug() {
    rep(i,0,N) {
        rep(j,0,N) {
            if (g[i][j] == INF) printf("- ");
            else printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int kase = 0;
    int tmp = -1;
    int n, country;
    int a, b;
    while (~scanf("%d", &tmp)) {
        init();
        rep(k,0,N-1) {
            if (tmp != -1) {
                n = tmp;
                tmp = -1;
            } else {
                scanf("%d", &n);
            }
            rep(i,0,n) {
                scanf("%d", &country);
                g[k][country-1] = g[country-1][k] = 1;
            }
        }
        floyd();
        printf("Test Set #%d\n", ++kase);
        scanf("%d", &n);
        rep(i,0,n) {
            scanf("%d%d", &a, &b);
            printf("%d to %d: %d\n", a, b, g[a-1][b-1]);
        }
        printf("\n");
    }
}



