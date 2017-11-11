/**
 * Created by LonelyEnvoy on 2017-11-11.
 * A. Local Extrema
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 1001

int n;
int a[MAX];
int k;

int main() {
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", a+i);
    }
    if (n <= 2) return puts("0"), 0;
    erep(i,1,n-2) {
        if ((a[i] > a[i-1] && a[i] > a[i+1])
            || a[i] < a[i-1] &&a[i] < a[i+1]) k++;
    }
    printf("%d\n", k);
}


