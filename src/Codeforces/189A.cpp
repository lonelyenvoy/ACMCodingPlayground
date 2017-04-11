/**
 * Created by LonelyEnvoy on 2017-4-11.
 * A. Cut Ribbon
 * Keywords: dp，完全背包问题
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; i++)
#define erep(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n-1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 4001

int v[3];
int n;
int d[MAX];

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    rep(i,0,3) {
        scanf("%d", v+i);
    }
    d[n] = 0;
    per(i,0,n+1) {
        if (d[i] != -1) {
            rep(j,0,3) {
                if (i-v[j] >= 0) {
                    d[i-v[j]] = 0;
                }
                if (i+v[j] <= n) {
                    d[i] = max(d[i], d[i+v[j]] + 1);
                }
            }
        }
    }
    printf("%d\n", d[0]);
}
