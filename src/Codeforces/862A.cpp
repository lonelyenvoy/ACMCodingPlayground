/**
 * Created by LonelyEnvoy on 2017-10-11.
 * A. Mahmoud and Ehab and the MEX
 * Keywords: simple math
 */

#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int hash[101];

int main() {
    int n;
    int x;
    scanf("%d%d", &n, &x);
    int tmp;
    rep(i,0,n) {
        scanf("%d", &tmp);
        hash[tmp] = 1;
    }
    int count = hash[x] ? 1 : 0;
    for (x--;x>=0;--x) {
        if (!hash[x]) count++;
    }
    printf("%d\n", count);
}


