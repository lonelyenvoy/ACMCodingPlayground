/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Frame Stacking
 * Keywords: topological sort
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define INF 0x3f3f3f3f

#define MAX 31
#define MAXF 26

struct Frame {
    int x1, y1, x2, y2;
    Frame() {
        x1 = y1 = INF;
        x2 = y2 = -1;
    }
};

bool exists[MAXF];
Frame frames[MAXF];

char matrix[MAX][MAX];
int n;
int m;

bool g[MAX][MAX];
int indegree[MAXF];

int numOfFrames;
char ans[MAXF+1];

inline void init() {
    memset(exists, false, sizeof(exists));
    rep(i,0,MAXF) frames[i] = Frame();
    memset(g, false, sizeof(g));
    memset(indegree, 0, sizeof(indegree));
    numOfFrames = 0;
}

bool isOnFrame(int k, int x, int y) {
    const Frame& f = frames[k];
    return ((y >= f.y1 && y <= f.y2) && (x == f.x1 || x == f.x2))
        || ((x >= f.x1 && x <= f.x2) && (y == f.y1 || y == f.y2));
}

void dfs(int level) {
    if (level == numOfFrames) {
        ans[level] = '\0';
        printf("%s\n", ans);
        return;
    }

    rep(i,0,MAXF) {
        if (!exists[i]) continue;
        if (indegree[i] == 0) {
            ans[level] = i + 'A';
            indegree[i]--;
            rep(j,0,MAX) {
                if (g[i][j]) indegree[j]--;
            }
            dfs(level+1);
            rep(j,0,MAX) {
                if (g[i][j]) indegree[j]++;
            }
            indegree[i]++;
        }
    }
}

int main() {
    char c;
    while (~scanf("%d%d", &n, &m)) {
        init();

        rep(i,0,n) {
            rep(j,0,m) {
                scanf("%c", &c);
                if (c == '\n') {
                    j--; continue;
                }
                if (c != '.') {
                    exists[c-'A'] = true;
                    Frame& f = frames[c-'A'];
                    if (i < f.x1) f.x1 = i;
                    if (j < f.y1) f.y1 = j;
                    if (i > f.x2) f.x2 = i;
                    if (j > f.y2) f.y2 = j;
                }
                matrix[i][j] = c;
            }
        }

        rep(i,0,n) {
            rep(j,0,m) {
                c = matrix[i][j];
                if (c != '.') {
                    rep(k,0,MAXF) {
                        if (k != c-'A' && exists[k] && isOnFrame(k, i, j)) {
                            g[k][c-'A'] = true;
                        }
                    }
                }
            }
        }
        rep(j,0,MAXF) {
            rep(i,0,MAXF) {
                indegree[j] += g[i][j];
            }
        }

        rep(i,0,MAXF) {
            if (exists[i]) numOfFrames++;
        }

        dfs(0);
    }
}



