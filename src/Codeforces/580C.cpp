/**
 * Created by LonelyEnvoy on 2017-8-23.
 * C. Kefa and Park
 * Keywords: dfs
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define INF 0x3f3f3f3f
#define MAX 100001

int n, m;
bool nodes[MAX];
bool vis[MAX];
vector<int> g[MAX];
int solution;

void dfs(int u, int cat) {
    if (cat > m) return;
    
    bool hasChild = false;
    int v;
    for (vector<int>::iterator itr = g[u].begin(), end = g[u].end(); itr != end; ++itr) {
        v = *itr;
        if (!vis[v]) {
            hasChild = true;
            vis[v] = 1;
            dfs(v, nodes[v] ? cat+1 : 0);
        }
    }
    if (!hasChild) solution++;
}

int main() {
    int tmp;
    scanf("%d%d", &n, &m);
    rep(i,0,n) {
        scanf("%d", &tmp);
        nodes[i] = (bool)tmp;
    }
    int u, v;
    rep(i,0,n-1) {
        scanf("%d%d", &u, &v);
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    vis[0] = 1;
    dfs(0, nodes[0]);
    printf("%d\n", solution);
    return 0;
}

