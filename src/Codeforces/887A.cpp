/**
 * Created by LonelyEnvoy on 2017-11-6.
 * A. Div. 64
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 101

char str[MAX];
int len;

int main() {
    scanf("%s", str);
    len = strlen(str);
    if (len < 7) puts("NO");
    else {
        bool flag = 0;
        int count = 0;
        rep(i,0,len) {
            if (str[i] == '1') flag = 1;
            else if (flag) count++;
        }
        puts(count >= 6 ? "YES" : "NO");
    }
}


