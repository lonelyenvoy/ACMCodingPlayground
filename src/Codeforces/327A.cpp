/**
 * Created by LonelyEnvoy on 2017-4-11.
 * A. Flipping Game
 * Keywords: brute force，暴力枚举，水题
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; i++)
#define erep(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n-1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 101

bool a[MAX];
int n;

void flip(int x, int y) {
    erep(i,x,y) {
        a[i] = !a[i];
    }
}

int numof1() {
    int count = 0;
    rep(i,0,n) {
        if (a[i]) count++;
    }
    return count;
}

int main() {
    scanf("%d", &n);
    int tmp;
    rep(i,0,n) {
        scanf("%d", &tmp);
        a[i] = tmp;
    }

    int maxSum = 0;
    int sum;
    rep(i,0,n) {
        rep(j,i,n) {
            flip(i,j);
            sum = numof1();
            if (sum > maxSum) maxSum = sum;
            flip(i,j);
        }
    }

    printf("%d\n", maxSum);
}
