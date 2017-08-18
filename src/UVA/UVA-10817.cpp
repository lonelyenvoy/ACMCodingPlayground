/**
 * Created by LonelyEnvoy on 2017-8-18.
 * Headmaster's Headache
 * Keywords: DP (complex / state compression)
 * See also: Rujia Liu's Book, page 286
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define INF 0x3f3f3f3f

#define MAXN 121
#define MAXS 9

int s, m, n;
int dp[MAXN][1<<MAXS][1<<MAXS];
int c[MAXN];
int teach[MAXN]; // the courses teacher[i] can teach

inline void init() {
    memset(dp, -1, sizeof(dp));
    memset(teach, 0, sizeof(teach));
}

// dp[i][s1][s2] = max( dp[i+1][s1][s2], dp[i+1][s1'][s2'] + c[i] )
int solve(int i, int s0, int s1, int s2) {
    if (i == m+n) return s2 == (1<<s)-1 ? 0 : INF;
    int& ans = dp[i][s1][s2];
    if (ans >= 0) return ans;
    ans = INF;
    if (i >= m) ans = solve(i+1, s0, s1, s2);
    int lastS0 = s0;
    int lastS1 = s1;
    s0 ^= teach[i] & s0;
    s1 = ((teach[i] ^ s1) & s2) ^ (teach[i] ^ s1);
    // or
    //s1 = ((s1 ^ (teach[i] & s1)) | (teach[i] & lastS0));
    s2 |= teach[i] & lastS1;
    return ans = min(ans, solve(i+1, s0, s1, s2) + c[i]);
}

int main() {
    char buf[50];
    char* token;
    char delim[] = " ";
    while (~scanf("%d%d%d", &s, &m, &n) && s) {
        getchar(); // eat "\n"
        init();
        bool first;
        rep(i,0,m+n) {
            fgets(buf, sizeof(buf), stdin);
            token = strtok(buf, delim);
            first = true;
            while (token != NULL) {
                first ? (c[i] = atoi(token)) : (teach[i] |= 1 << (atoi(token) - 1));
                first = false;
                token = strtok(NULL, delim);
            }
        }
        printf("%d\n", solve(0, (1<<s)-1, 0, 0));
    }
}

