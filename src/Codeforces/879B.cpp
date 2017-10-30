/**
 * Created by LonelyEnvoy on 2017-10-30.
 * B. Table Tennis
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

typedef long long ll;

#define min(a,b) (((a)<(b))?(a):(b))

#define MAX 501

int n,k;
int a[MAX];

void tail(int x) {
    int tmp = a[x];
    rep(i,x,n) {
        a[i] = a[i+1];
    }
    a[n-1] = tmp;
}

int main() {
    ll tmp;
    scanf("%d%I64d", &n, &tmp); 
    k = min(n-1, tmp);
    rep(i,0,n) scanf("%d", a+i);
    int count = 0;
    while (count < k) {
        if (a[0] < a[1]) tail(0), count=1;
        else tail(1), ++count;
    }
    printf("%d\n", a[0]);
}


