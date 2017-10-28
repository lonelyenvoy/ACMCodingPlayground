/**
 * Created by LonelyEnvoy on 2017-10-29.
 * A. Book Reading
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 101

int n, t;
int a[MAX];
int ans;

int main() {
    scanf("%d%d", &n, &t);
    rep(i,0,n) scanf("%d", a+i);
    for (ans = 0; ans < n; ++ans) {
        if (t <= 0) break;
        t -= 86400 - a[ans];
    }
    printf("%d\n", ans);
}


