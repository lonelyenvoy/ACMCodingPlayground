#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
using namespace std;  

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int maxn = 55;  
int n, m, k;  
bool map[103][103];  
int idx[103][103];  
int id;  
vector <int> edge[maxn];  
int pre[maxn];  
bool vis[maxn];  
bool dfs(int u) {  
    rep(i,0,(int)edge[u].size()) {
        int v = edge[u][i];  
        if(vis[v])  
            continue;  
        vis[v] = 1;  
        if(pre[v] == -1 || dfs(pre[v])) {  
            pre[v] = u;  
            return 1;  
        }  
    }  
    return 0;  
}  
int dir[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };  
int main() {  
    while(~scanf("%d%d", &n, &m) && n && m) {  
        scanf("%d", &k);  
        int x, y;  
        memset(map, 0, sizeof(map));  
        while(k--) {  
            scanf("%d%d", &x, &y);  
            x--; y--;  
            map[x][y] = 1;  
        }  
        id = 0;  
        rep(i,0,n)
            rep(j,0,m)
                if(!map[i][j])  
                    idx[i][j] = id++;  
        rep(i,0,id)
            edge[i].clear();  
        rep(i,0,n)
            rep(j,0,m)
                if(!map[i][j] && (i + j & 1)) {  
                    for(k = 0; k < 4; k++) {  
                        int x = i + dir[k][0];  
                        int y = j + dir[k][1];  
                        if(x < 0 || x >= n || y < 0 || y >= m || map[x][y])  
                            continue;  
                        edge[idx[i][j]].push_back(idx[x][y]);  
                    }  
                }  
        memset(pre, -1, sizeof(int) * id);  
        int cnt = 0;  
        rep(i,0,n)
            rep(j,0,m)
                if(!map[i][j] && (i + j & 1)) {  
                    memset(vis, 0, sizeof(bool) * id);  
                    if(dfs(idx[i][j])) cnt++;  
                }  
        printf("%d\n", cnt);  
    }  
    return 0;  
}  
