/**
 * Created by LonelyEnvoy on 2017-10-25.
 * B. The Eternal Immortality
 * Keywords: simple math
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

typedef long long ll;

int main() {
    ll a,b;
    scanf("%I64d%I64d", &a, &b);
    if (a == b) return puts("1"), 0;
    ll ans = 1;
    for (ll i = a+1; i <= b; ++i) {
        ans *= i;
        ans %= 10;
        if (ans == 0) break;
    }
    printf("%I64d\n", ans);
}

