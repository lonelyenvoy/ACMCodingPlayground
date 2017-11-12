/**
 * Created by LonelyEnvoy on 2017-11-12.
 * B. Buggy Robot
 * Keywords: greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int c[256];

int main() {
    int n;
    scanf("%d", &n);
    char k;
    getchar();
    while (n--) scanf("%c", &k), c[k]++;
    printf("%d\n", min(c['U'], c['D'])*2 + min(c['L'], c['R'])*2);
}


