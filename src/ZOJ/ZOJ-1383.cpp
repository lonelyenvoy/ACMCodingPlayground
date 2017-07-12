/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Binary Numbers
 * Keywords: 位运算，水题
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

int main() {
    int n;
    scanf("%d", &n);
    int oct;
    const int bound = sizeof(int)*8;
    bool first;
    while (n--) {
        first = true;
        scanf("%d", &oct);
        rep(i,0,bound) {
            if ((1 << i) & oct) {
                if (first) {
                    first = false;
                    printf("%d", i);
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }
}

