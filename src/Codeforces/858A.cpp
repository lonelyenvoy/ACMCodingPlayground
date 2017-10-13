/**
 * Created by LonelyEnvoy on 2017-10-14.
 * A. k-rounding
 * Keywords: implementation, simple math, brute force
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

typedef long long ll;

int k;
ll n;

bool matches(ll a) {
    int count = 0;
    while (a%10 == 0) a/=10, ++count;
    return count >= k;
}

int getDelta(int a) {
    switch (a % 10) {
    case 0: 
        return 1;
    case 1:
    case 3:
    case 7:
    case 9:
        return 10;
    case 2:
    case 4:
    case 6:
    case 8:
        return 5;
    case 5:
        return 2;
    }
}

int main() {
    scanf("%I64d%d", &n, &k);
    if (k == 0) return printf("%I64d\n", n), 0;
    int delta = getDelta(n);
    int m;
    for (m = delta; ; m += delta) {
        if (matches(n*m)) break;
    }
    printf("%I64d\n", n*m);
}


