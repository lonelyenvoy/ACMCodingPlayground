/**
 * Created by LonelyEnvoy on 2017-8-25.
 * A. Chess Tourney
 * Keywords: simple sorting
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define INF 0x3f3f3f3f
#define MAX 201

int n;
int a[MAX];

int main() {
    scanf("%d", &n);
    rep(i,0,2*n) scanf("%d", a+i);
    sort(a, a+2*n);
    printf(a[n] != a[n-1] ? "YES\n" : "NO\n");
}


