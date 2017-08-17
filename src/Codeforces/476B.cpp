/**
 * Created by LonelyEnvoy on 2017-8-17.
 * B. Dreamoon and WiFi
 * Keywords: bit operation, math
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 11

char ori[MAX];
char act[MAX];

int ones;
int zeros;
int m;

double solve() {
    if (ones < 0 || zeros < 0) return 0;
    if (ones + zeros != m) return 0;
    if (ones == 0 && zeros == 0) return 1;

    int bound = (1<<m);
    int curr;
    int count = 0;
    rep(i,0,bound) {
        curr = 0;
        rep(j,0,m) {
            if ((1<<j) & i) curr++;
        }
        if (curr == ones && m - curr == zeros) count++;
    }
    return (double)count / bound;
}

int main() {
    scanf("%s", ori);
    scanf("%s", act);
    int n = strlen(ori);
    int oriOnes = 0;
    int actOnes = 0;
    int actZeros = 0;
    rep(i,0,n) {
        if (ori[i] == '+') oriOnes++;
        switch (act[i]) {
            case '+': actOnes++; break;
            case '-': actZeros++; break;
            case '?': m++; break;
        }
    }
    int oriZeros = n - oriOnes;

    ones = oriOnes - actOnes;
    zeros = oriZeros - actZeros;
    printf("%.12lf\n", solve());
}

