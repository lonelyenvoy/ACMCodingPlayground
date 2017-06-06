/**
 * Created by LonelyEnvoy on 2017-6-7.
 * Quicksum
 * Keywords: 水题
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 257

int main() {
    char str[MAX];
    int len;
    int ans;
    while (fgets(str, MAX, stdin)) {
        if (str[0] == '#') break;
        ans = 0;
        len = strlen(str) - 1;
        rep(i,0,len) {
            if (str[i] == ' ') continue;
            ans += (i+1) * (str[i] - 'A' + 1);
        }
        printf("%d\n", ans);
    }
}

