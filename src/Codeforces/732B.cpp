/**
 * Created by LonelyEnvoy on 2017-8-16.
 * B. Cormen — The Best Friend Of a Man
 * Keywords: greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 501

int plan[MAX];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    rep(i,0,n) {
        scanf("%d", plan+i);
    }
    int add = 0;
    int delta;
    erep(i,1,n-1) {
        delta = k - (plan[i] + plan[i-1]);
        if (delta > 0) {
            add += delta;
            plan[i] += delta;
        }
    }
    
    printf("%d\n", add);
    bool first = true;
    rep(i,0,n) {
        if (!first) printf(" ");
        printf("%d", plan[i]);
        first = false;
    }
    printf("\n");
}

