/**
 * Created by LonelyEnvoy on 2017-7-26.
 * B. Taxi
 * Keywords: simple implementation, greedy
 */

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define erep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i++)

int n;
int c[5];
int taxi;

int main() {
    int tmp;
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", &tmp);
        c[tmp]++;
    }
    while (c[4]-- > 0) taxi++;
    while (c[2] > 1) {
        c[2] -= 2;
        taxi++;
    }
    while (c[1] > 0 && c[3] > 0) {
        c[1]--;
        c[3]--;
        taxi++;
    }

    // handle remaining groups
    if (c[3]) {
        taxi += c[3];
        if (c[2]) {
            taxi++;
        }
    } else {
        if (!c[2]) {
            taxi += ceil((double)c[1] / 4);
        } else {
            taxi++;
            if (c[1] >= 2) {
                c[1] -= 2;
                //c[2] = 0;
                taxi += ceil((double)c[1] / 4);
            }
        }
    }

    printf("%d\n", taxi);
}


