/**
 * Created by LonelyEnvoy on 2017-10-12.
 * Mahmoud and Ehab and the xor
 * Keywords: simple math, xor, constructive algorithm
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int e = 1<<17;
int n, x;
int sum;

int main() {
    scanf("%d%d", &n, &x);
    if (n == 1) printf("YES\n%d\n", x);
    else if (n == 2) printf(x == 0 ? "NO\n" : "YES\n%d %d\n", 0, x);
    else {
        puts("YES");
        erep(i,1,n-3) printf("%d ", i), x^=i;
        printf("%d %d %d\n", e, e^(e<<1), (e<<1)^x);
    }
}

