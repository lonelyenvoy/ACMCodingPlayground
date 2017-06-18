/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Fire Net
 * A better solution
 * Keywords: 二分匹配
 */

// 参考资料：http://blog.csdn.net/jeremygjy/article/details/47087593

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int MAXN = 4;

bool vis[MAXN*MAXN*MAXN];
int Map[MAXN+2][MAXN+2];
int id_v[MAXN+2][MAXN+2];
int id_h[MAXN+2][MAXN+2];
int con[MAXN*MAXN*MAXN];
int idcnt, endcnt;
int n;
const int MAXEN = 16;
const int MAXEM = MAXEN * 2;

struct node{
    int v;
    node *next;
}Edges[MAXEM*2+10], *adj[MAXEN+10], *ecnt=Edges;

void addedge(int u, int v){
    ++ecnt;
    ecnt->v = v;
    ecnt->next = adj[u];
    adj[u] = ecnt;
}

bool dfs(int u){
    for(node *p=adj[u];p;p=p->next){
        if(!vis[p->v]){
            vis[p->v] = true;
            if(!con[p->v] || dfs(con[p->v])){
                con[u] = p->v;
                con[p->v] = u;
                return true;
            }
        }
    }
    return false;
}

int work(){
    int ret = 0;
    erep(i,1,endcnt) {
        if(!con[i]){
            memset(vis, 0, sizeof vis);
            ret += dfs(i);
        }
    }
    return ret;
}

bool read(){
    char t[20];
    scanf("%d", &n);
    if(!n) return false;
    erep(i,1,n) {
        scanf("%s", t);
        rep(j,0,n)
            Map[i][j+1] = t[j] == 'X' ? 0 : 1;
    }
    return true;
}

void prepare(){
    idcnt=0;
    memset(adj, 0, sizeof adj);
    ecnt=Edges;
    memset(con, 0, sizeof con);
    erep(i,1,n) {
        erep(j,1,n) if(Map[i][j]){
            if(!Map[i][j-1]) idcnt++;
            id_h[i][j] = idcnt;
        }
    }
    endcnt = idcnt;
    erep(i,1,n) {
        erep(j,1,n) if(Map[j][i]) {
            if(!Map[j-1][i]) idcnt++;
            id_v[j][i] = idcnt;
        }
    }
    erep(i,1,n) {
        erep(j,1,n) if(Map[i][j]){
            addedge(id_h[i][j], id_v[i][j]);
            addedge(id_v[i][j], id_h[i][j]);
        }
    }
}

int main(){
    while(read()){
        prepare();
        printf("%d\n", work());
    }
    return 0;
}

