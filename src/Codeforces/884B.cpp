/**
 * Created by LonelyEnvoy on 2017-11-3.
 * B. Japanese Crosswords Strike Back
 * Keywords: simple math
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n, k;
int sum;

int main() {
    int tmp;
    scanf("%d%d", &n, &k);
    rep(i,0,n) scanf("%d", &tmp), sum += tmp;
    puts(sum + n-1 == k ? "YES" : "NO");
}


