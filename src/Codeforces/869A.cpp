/**
 * Created by LonelyEnvoy on 2017-10-7.
 * A. The Artful Expedient
 * Keywords: brute force, bit operation
 */

// Under any circumstances, the result will be "Karen".
// See the property of bit operation for details.
//
// a^b=c => a^c=a^(a^b)=(a^a)^b=0^b=b

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int x[2001];
int y[2001];
bool hash[2000001];
int n;

int main() {
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", x+i), hash[x[i]] = 1;
    rep(i,0,n) scanf("%d", y+i), hash[x[i]] = 1;
    int count = 0;
    int tmp;
    rep(i,0,n) {
        rep(j,0,n) {
            tmp = x[i] ^ y[j];
            if (tmp > 0 && tmp < 2000001 && hash[tmp]) count++;
        }
    }
    puts((count & 1) ? "Koyomi" : "Karen");
}


