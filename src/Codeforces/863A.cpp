/**
 * Created by LonelyEnvoy on 2017-10-11.
 * A. Quasi-palindrome
 * Keywords: simple strings
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

char str[20];
int len;

bool palin() {
    rep(i,0,len/2) {
        if (str[i] != str[len-i-1]) return false;
    }
    return true;
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    while (str[len-1] == '0') len--;
    puts(palin() ? "YES" : "NO");
}


