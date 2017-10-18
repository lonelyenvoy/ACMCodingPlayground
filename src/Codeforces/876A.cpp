/**
 * Created by LonelyEnvoy on 2017-10-18.
 * A. Trip For Meal
 * Keywords: simple math
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n;
int a,b,c;
int m;

int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    m=min(a,b);
    if (n == 1) return puts("0"), 0;
    if (n == 2) return printf("%d\n", m), 0;
    if (m<c) printf("%d\n", m*(n-1));
    else printf("%d\n", m+c*(n-2));
}


