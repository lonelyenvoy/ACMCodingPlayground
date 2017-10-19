/**
 * Created by LonelyEnvoy on 2017-10-19.
 * B. Divisiblity of Differences
 * Keywords: math
 */

// Given two positive integer a and b
// if a % m == b % m (m is a positive integer)
// then (a - b) % m = 0  =>  m is a multiple of (a-b)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 100001

int n, k, m;
int a[MAX];
int mod[MAX];
int c[MAX];
int peak, best;

int main() {
    scanf("%d%d%d", &n, &k, &m);
    rep(i,0,n) scanf("%d", a+i), mod[i] = a[i] % m, c[mod[i]]++;
    rep(i,0,m) if (c[i] > best) peak = i, best = c[i];
    if (best < k) return puts("No"), 0;
    puts("Yes");
    int count = 0;
    bool first = true;
    rep(i,0,n) {
        if (count >= k) break;
        if (mod[i] == peak) {
            if (!first) printf(" ");
            printf("%d", a[i]);
            first = false;
            count++;
        }
    }
    printf("\n");
}


