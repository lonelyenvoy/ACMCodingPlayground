/**
 * Created by LonelyEnvoy on 2017-10-3.
 * A. Between the Offices 
 * Keywords: simple strings
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 101

int n;
char last;
char curr;
int s;
int f;

int main() {
    scanf("%d", &n);
    getchar();
    rep(i,0,n) {
        last = curr;
        scanf("%c", &curr);
        if (last == 'S' && curr == 'F') s++;
        else if (last == 'F' && curr == 'S') f++;
    }
    printf(s > f ? "YES\n" : "NO\n");

}


