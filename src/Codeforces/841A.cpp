/**
 * Created by LonelyEnvoy on 2017-10-28.
 * A. Generous Kefa
 * Keywords: simple math
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n, k;
int c[26];
int peak;

int main() {
    scanf("%d%d", &n, &k);
    getchar();
    char tmp;
    rep(i,0,n) {
        scanf("%c", &tmp);
        peak = max(peak, ++c[tmp-'a']);
    }
    puts(peak <= k ? "YES" : "NO");
}


