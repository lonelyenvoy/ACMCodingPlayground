/**
 * Created by LonelyEnvoy on 2017-8-9.
 * It's not a Bug, it's a Feature!
 * Keywords: 隐式图搜索, dijkstra, BFS
 */
 
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define erep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i++)

#define INF 0x3f3f3f3f

#define MAX_BUGS 20
#define MAX_PATCHES 100

char patchesSrc[MAX_PATCHES][MAX_BUGS];
char patchesDest[MAX_PATCHES][MAX_BUGS];
int patchesCost[MAX_PATCHES];

int n; // number of bugs
int m; // number of patches

bool vis[1<<MAX_BUGS];
int dis[1<<MAX_BUGS];

struct Node {
    int status;
    int totalCost;

    bool operator<(const Node& rhs) const {
        return totalCost > rhs.totalCost;
    }
};

inline void init() {
    memset(vis, false, sizeof(vis));
    memset(dis, INF, sizeof(dis));
}

int dijkstra() {
    priority_queue<Node> q;
    Node curr, next;
    curr.status = (1 << n) - 1;
    curr.totalCost = 0;

    q.push(curr);
    dis[curr.status] = 0;
    while (!q.empty()) {
        curr = q.top();
        q.pop();
        if (vis[curr.status]) continue;
        vis[curr.status] = true;
        if (curr.status == 0) return curr.totalCost;
        rep(k,0,m) {
            bool canPatch = true;
            rep(i,0,n) {
                if ((patchesSrc[k][i] == '+' && !((1 << (n-i-1)) & curr.status))
                    || (patchesSrc[k][i] == '-' && (1 << (n-i-1)) & curr.status)) {
                    canPatch = false;
                    break;
                }
            }
            if (!canPatch) continue;
            next.totalCost = curr.totalCost + patchesCost[k];
            next.status = curr.status;
            rep(i,0,n) {
                next.status |= (((patchesDest[k][i] == '+') << (n-i-1)));
                next.status &= ~(((patchesDest[k][i] == '-') << (n-i-1)));
            }
            if (next.status == curr.status) continue;
            if (next.totalCost < dis[next.status]) {
                dis[next.status] = next.totalCost;
                q.push(next);
            }
        }
    }
    return -1;
}


int main() {
    //freopen("acm.out", "w", stdout);
    int kase = 0;
    int ans;
    while (~scanf("%d%d", &n, &m) && n && m) {
        rep(i,0,m) {
            scanf("%d%s%s", &patchesCost[i], patchesSrc[i], patchesDest[i]);
        }
        init();
        ans = dijkstra();
        printf("Product %d\n", ++kase);
        if (ans != -1) {
            printf("Fastest sequence takes %d seconds.\n\n", ans);
        } else {
            printf("Bugs cannot be fixed.\n\n");
        }
    }
}



