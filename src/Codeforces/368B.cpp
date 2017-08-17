/**
 * Created by LonelyEnvoy on 2017-8-17.
 * B. Sereja and Suffixes
 * Keywords: simple greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 100001

int n, m;
int arr[MAX];
bool exist[MAX];
int distinct[MAX];

int main() {
    scanf("%d%d", &n, &m);
    rep(i,0,n) {
        scanf("%d", arr+i);
    }
    distinct[n-1] = 1;
    exist[arr[n-1]] = 1;
    per(i,0,n-1) { // starts from (n-2)
        if (!exist[arr[i]]) {
            distinct[i] = distinct[i+1] + 1;
            exist[arr[i]] = 1;
        } else {
            distinct[i] = distinct[i+1];
        }
    }

    int q;
    rep(i,0,m) {
        scanf("%d", &q);
        printf("%d\n", distinct[q-1]);
    }
}

