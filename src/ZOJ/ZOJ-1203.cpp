/**
 * Created by LonelyEnvoy on 2017-5-4.
 * Highways
 * Keywords: 图论，最小生成树（Kruskal/Prim），并查集
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <limits>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; i++)
#define erep(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n-1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 10000

struct Cord {
    double x,y;
};

struct Edge {
    int u,v;
    double w;

    bool operator<(const Edge& e) const {
        return this->w > e.w;
    }
};

Cord cords[MAX];
priority_queue<Edge> edges;
int n;

int ufsets[MAX];

inline void init() {
    memset(ufsets, -1, sizeof(ufsets));
    while (!edges.empty()) {
        edges.pop();
    }
}

int find(int u) {
    if (ufsets[u] < 0) return u;
    return ufsets[u] = find(ufsets[u]);
}

bool join(int u1, int u2) {
    u1 = find(u1);
    u2 = find(u2);
    if (u1 == u2) return false;
    if (ufsets[u1] <= ufsets[u2]) { // set u1 is bigger than u2
        ufsets[u1] += ufsets[u2];
        ufsets[u2] = u1;
    } else {
        ufsets[u2] += ufsets[u1];
        ufsets[u1] = u2;
    }
    return true;
}

int numOfSets() {
    int count = 0;
    rep(i,0,n) {
        if (ufsets[i] < 0) {
            count++; // 易出错
        }
    }
    return count;
}

double kruskal() {
    Edge e;
    double sumWeight = 0;
    while (numOfSets() > 1) { // 易出错
        e = edges.top();
        edges.pop();
        if (find(e.u) != find(e.v)) {
            join(e.u, e.v);
            sumWeight += e.w;
        }
    }
    return sumWeight;
}

int main() {
    int kase = 0;
    Edge e;
    while (~scanf("%d", &n) && n) {
        init();
        rep(i,0,n) {
            scanf("%lf%lf", &cords[i].x, &cords[i].y);
        }
        rep(i,0,n) {
            rep(j,i+1,n){
                e.u = i;
                e.v = j;
                e.w = sqrt((cords[i].x - cords[j].x) * (cords[i].x - cords[j].x)
                            + (cords[i].y - cords[j].y) * (cords[i].y - cords[j].y));
                edges.push(e);
            }
        }
        if (kase > 0) {
            printf("\n");
        }
        printf("Case #%d:\n", ++kase);
        printf("The minimal distance is: %.2lf\n", kruskal());
    }
}
