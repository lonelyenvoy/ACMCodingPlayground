/**
 * Created by LonelyEnvoy on 2017-8-17.
 * C. Number of Ways
 * Keywords: brute force
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 500001

typedef long long ll;

int n;
ll arr[MAX];
ll sum;
int pos[MAX];
int k;

ll solve() {
    rep(i,0,n) {
        sum += arr[i];
    }

    if (n < 3 || sum % 3 != 0) return 0;

    ll bound = sum / 3;
    ll solution = 0;
    ll curr = 0;
    rep(i,0,n-2) { // [0, n-3]
        curr += arr[i];
        if (curr == bound) {
            pos[k++] = i+1;
        }
    }
    curr = 0;
    per(i,2,n) { // [2, n-1]
        curr += arr[i];
        if (curr == bound) {
            solution += lower_bound(pos, pos+k, i) - pos;
        }
    }
    return solution;
}

int main() {
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%I64d", arr+i);
    }
    printf("%I64d\n", solve());
}

