/**
 * Created by LonelyEnvoy on 2017-10-6.
 * A. Bark to Unlock
 * Keywords: simple strings
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n;
char target[3];
char known[101][3];
vector<int> possible;
char buf[5];

int main() {
    scanf("%s", target);
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%s", known[i]);
        if (known[i][0] == target[0] || known[i][0] == target[1]
            || known[i][1] == target[0] || known[i][1] == target[1]) {
            possible.push_back(i);
        }
    }
    int size = possible.size();
    bool found = false;
    rep(i,0,size) {
        rep(j,0,size) {
            memcpy(buf, known[possible[i]], sizeof(char)*2);
            memcpy(buf+2, known[possible[j]], sizeof(char)*2);
            if (strstr(buf, target)) {
                found = true;
                goto done;
            }
        }
    }
done:
    printf(found ? "YES\n" : "NO\n");
}


