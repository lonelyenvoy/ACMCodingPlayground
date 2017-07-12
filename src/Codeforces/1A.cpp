#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll x, y, a, ans;
    scanf("%I64d %I64d %I64d", &x, &y, &a);
    ans = (ll)ceil((double)x/a) * (ll)ceil((double)y/a);
    printf("%I64d\n", ans);
}


