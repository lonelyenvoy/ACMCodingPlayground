/**
 * Created by LonelyEnvoy on 2017-8-17.
 * A. Joysticks
 * Keywords: simple greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

inline void discharge(int &x) {
    x -= 2;
}

inline void charge(int &x) {
    x += 1;
}

int main() {
    int a, b;
    int m = 0;
    scanf("%d%d", &a, &b);
    for (;;m++) {
        if ((a <= 1 && b <= 1) || (a <= 0 || b <= 0)) break;
        if (a < b) {
            charge(a);
            discharge(b);
        } else {
            charge(b);
            discharge(a);
        }
    }
    printf("%d\n", m);
}

