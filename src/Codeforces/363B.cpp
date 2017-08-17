/**
 * Created by LonelyEnvoy on 2017-8-17.
 * B. Fence
 * Keywords: brute force
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 200000

int n, k;
int heights[MAX];
int sum[MAX];

int solve() {
    sum[0] = heights[0];
    rep(i,0,n) {
        sum[i] = sum[i-1] + heights[i];
    }
    int curr;
    int best = sum[k-1];
    int pos = 0;
    erep(i,0,n-k) {
        curr = i == 0 ? sum[k-1] : sum[i+k-1] - sum[i-1];
        if (curr < best) {
            best = curr;
            pos = i;
        }
    }
    return pos;
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i,0,n) {
        scanf("%d", heights+i);
    }
    printf("%d\n", solve()+1);
}

