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

//inline int round(double x) {
//    return x > 0.0 ? floor(x + 0.5) : ceil(x - 0.5);
//}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%I64d%I64d", &a, &b);
        r = pow(a*b, 1.0/3);
        puts(abs(r - round(r)) < eps ? "YES" : "NO");
    }
}


