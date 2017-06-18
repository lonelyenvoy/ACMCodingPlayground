/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Place the Robots
 * Keywords: 二分匹配
 */

// 参考资料：http://blog.csdn.net/acdreamers/article/details/8654005

#include <iostream>  
#include <cstring>  
#include <cstdio>  
using namespace std;  

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int N = 1250;  
  
char map[N][N];  
int col[N][N],row[N][N];  
int link[N],head[N];  
bool vis[N];  
int cnt,n,m;  
int r,c;  
  
struct Edge {  
    int to;  
    int next;  
};  
  
Edge edge[N*N];  
  
void init() {  
    cnt = 0;  
    memset(head,-1,sizeof(head));  
    memset(col,0,sizeof(col));  
    memset(row,0,sizeof(row));  
}  
  
void add(int u,int v) {  
    edge[cnt].to = v;  
    edge[cnt].next = head[u];  
    head[u] = cnt++;  
}  
  
bool dfs(int u) {  
    for(int i=head[u]; ~i; i=edge[i].next) {  
        int v = edge[i].to;  
        if(!vis[v]) {  
            vis[v] = 1;  
            if(link[v] == -1 || dfs(link[v])) {  
                link[v] = u;  
                return true;  
            }  
        }  
    }  
    return false;  
}  
  
int match() {  
    int ans = 0;  
    memset(link,-1,sizeof(link));  
    erep(i,1,r) {  
        memset(vis,0,sizeof(vis));  
        if(dfs(i)) ans++;  
    }  
    return ans;  
}  
  
int main() {  
    int T,tt = 1;  
    cin>>T;  
    while(T--) {  
        init();  
        cin>>n>>m;  
        erep(i,1,n)
            erep(j,1,m)
                cin>>map[i][j];  
        r = c = 1;  
        erep(i,1,n) {  
            erep(j,1,m) {  
                if(map[i][j] != '#' && row[i][j] == 0) {  
                    for(int k=j; map[i][k] != '#' && k <= m; k++)  
                        row[i][k] = r;  
                    ++r;  
                }  
                if(map[i][j] != '#' && col[i][j] == 0) {  
                    for(int k=i; map[k][j] != '#' && k <= n; k++)  
                        col[k][j] = c;  
                    ++c;  
                }  
            }  
        }  
        erep(i,1,n)
            erep(j,1,m)
                if(map[i][j] == 'o' && row[i][j] != 0 && col[i][j] != 0)  
                    add(row[i][j],col[i][j]);  
        printf("Case :%d\n",tt++);  
        printf("%d\n",match());  
    }  
    return 0;  
}  


