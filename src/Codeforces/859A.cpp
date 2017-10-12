/**
 * Created by LonelyEnvoy on 2017-10-12.
 * A. Declined Finalists
 * Keywords: simple greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int main() {
    int k, tmp, peak = -1;
    scanf("%d", &k);
    while (k--) scanf("%d", &tmp), peak = max(peak, tmp);
    printf("%d\n", max(peak-25, 0));
}

