/**
 * Created by LonelyEnvoy on 2017-11-8.
 * A. The Meaningless Game
 * Keywords: math, number theory
 */

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

typedef long long ll;

#define eps 1e-5

int n;
ll a, b;
double r;
ll lr;

//inline int round(double x) {
//    return x > 0.0 ? floor(x + 0.5) : ceil(x - 0.5);
//}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%I64d%I64d", &a, &b);
        r = pow(a*b, 1.0/3);
        lr = round(r);
        puts(abs(r - lr) < eps && a%lr == 0 && b%lr == 0 ? "YES" : "NO");
    }
}


