/**
 * Created by LonelyEnvoy on 2017-10-19.
 * A. Chores
 * Keywords: very simple question
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n,k,x;
int sum;

int main() {
    scanf("%d%d%d", &n, &k, &x);
    sum = k*x;
    int tmp;
    rep(i,0,n-k) scanf("%d", &tmp), sum += tmp;
    printf("%d\n", sum);
}


