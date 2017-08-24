/**
 * Created by LonelyEnvoy on 2017-8-24.
 * C. Two TVs
 * Keywords: greedy
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define INF 0x3f3f3f3f
#define MAX 200001

int n;
map<int, int> workload;

bool solve() {
    int curr = 0;
    for (map<int, int>::iterator itr = workload.begin(), end = workload.end(); itr != end; ++itr) {
        curr += itr->second;
        if (curr > 2) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int a, b;
    rep(i,0,n) {
        scanf("%d%d", &a, &b);
        workload[a]++;
        workload[b+1]--;
    }
    printf(solve() ? "YES\n" : "NO\n");
}


