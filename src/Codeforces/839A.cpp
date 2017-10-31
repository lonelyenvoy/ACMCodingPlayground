/**
 * Created by LonelyEnvoy on 2017-10-31.
 * A. Ayra and Bran
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n,k;

int main() {
    scanf("%d%d", &n, &k);
    int candy, index, tmp;
    int total = 0;
    for (index = 0; index < n; ++index) {
        if (k <= 0) break;
        scanf("%d", &candy);
        total += candy;
        tmp = min(8, candy);
        total -= tmp;
        k -= tmp;
    }
    printf("%d\n", k <= 0 ? index : -1);
}


