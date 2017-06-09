/**
 * Created by LonelyEnvoy on 2017-6-9.
 * Jungle Roads
 * Keywords: 最小生成树，kruskal/prim，并查集
 */

// 注意scanf同时读取数字和字符时遇到的问题
//
// scanf("%c%d", &c, &num) 会读入上一行的换行符，c == '\n'，无法读取num。
// 使用 scanf("%*c%c%d", &c, &num) 忽略回车解决
//
// scanf("%d%c", &num, &c) 正常读取num，c == '\n'
// 在这种情况下同时读入一串数字以及回车时，系统将其全部保存进缓冲队列，并且与%d的格式的num和%c格式的c一一匹配。num得到数字，c得到字符回车。
// 使用 scanf("%d%c%*c", &num, &c) 忽略回车解决

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAXE 76

struct Edge {
    int u, v, w;
};

bool operator<(const Edge& e1, const Edge& e2) {
    return e1.w > e2.w;
}

int n;
priority_queue<Edge> edges;
int ufsets[MAXE];

inline void init() {
    while (!edges.empty()) {
        edges.pop();
    }
    memset(ufsets, -1, sizeof(ufsets));
}

int find(int u) {
    if (ufsets[u] < 0) return u;
    return ufsets[u] = find(ufsets[u]);
}

bool join(int u1, int u2) {
    u1 = find(u1);
    u2 = find(u2);
    if (u1 == u2) return false;
    if (ufsets[u1] <= ufsets[u2]) {
        ufsets[u1] += ufsets[u2];
        ufsets[u2] = u1;
    } else {
        ufsets[u2] += ufsets[u1];
        ufsets[u1] = u2;
    }
    return true;
}

int kruskal() {
    int countEdge = 0;
    int sum = 0;    
    Edge e;
    while (countEdge < n - 1 && !edges.empty()) {
        e = edges.top();
        edges.pop();
        if (!join(e.u, e.v)) continue;
        sum += e.w;
        countEdge++;
    }
    if (countEdge != n - 1) return -1;
    return sum;
}

int main() {
    char src, dest;
    int k;
    int dis;
    Edge e;
    while (~scanf("%d", &n) && n) {
        init();
        rep(i,0,n-1) {
            src = k = 0;
            scanf("%*c%c%d", &src, &k);
            while (k--) {
                scanf("%*c%c%d", &dest, &dis);
                e.u = src - 'A';
                e.v = dest - 'A';
                e.w = dis;
                edges.push(e);
            }
        }
        printf("%d\n", kruskal());
    }
}


