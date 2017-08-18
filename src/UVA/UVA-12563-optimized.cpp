/**
 * Created by LonelyEnvoy on 2017-8-18.
 * Jin Ge Jin Qu hao
 * Keywords: dp
 * Optimized solution (20ms -> 10ms)
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAXN 51
#define MAXT 9679

struct Node {
    int count;
    int time;
};

int v[MAXN];
Node dp[MAXN][MAXT];
int n, t;

int ansCount;
int ansTime;

void solve() {
    erep(i,1,n) {
        erep(j,0,t) {
            dp[i][j] = dp[i-1][j];
            if (j > v[i] 
                && (dp[i][j].count < dp[i-1][j-v[i]].count+1
                    || (dp[i][j].count == dp[i-1][j-v[i]].count+1
                    && dp[i][j].time < dp[i-1][j-v[i]].time+v[i]))) {
                dp[i][j].time = dp[i-1][j-v[i]].time+v[i];
                dp[i][j].count = dp[i-1][j-v[i]].count+1;
            }
        }
    }
    
    ansCount = dp[n][t].count + 1;
    ansTime = dp[n][t].time + 678;
}

int main() {
    int kase;
    scanf("%d", &kase);
    rep(k,0,kase) {
        scanf("%d%d", &n, &t);
        erep(i,1,n) {
            scanf("%d", v+i);
        }
        solve();
        printf("Case %d: %d %d\n", k+1, ansCount, ansTime);
    }
}

