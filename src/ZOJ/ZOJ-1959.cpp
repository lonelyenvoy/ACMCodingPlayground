/**
 * Created by LonelyEnvoy on 2017-6-8.
 * Quadtree II
 * Keywords: 四分树，dfs，前序遍历
 * Warning: Aiming to achieve a higher efficiency, this code causes a memory leak as a side effect, which is unacceptable in engineering and should not be imitated.
 */

#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 513

struct Node {
    bool color; // B -> 1, W -> 0
    bool hasChild;
    Node* childs[4];
};

int n;
bool g[MAX][MAX]; // B -> 1, W -> 0
Node* root;

inline void init() {
    root = new Node();
}

void read() {
    char tmp[50];
    char buffer[330];
    int bits;
    scanf("%*s%*s%d", &n);
    rep(i,0,8) scanf("%*s");
    rep(i,0,n) {
        scanf("%s", buffer);
        rep(j,0,n/8) {
            sscanf(buffer + 5 * j, "%[^,]", tmp);
            sscanf(tmp + 2, "%x", &bits);
            rep(k,0,8) {
                g[i][j*8+k] = bits & (1 << k);
            }
        }
    }
    scanf("%*s");
}

bool judgeSame(int r, int c, int len) {
    rep(i,r,r+len) {
        rep(j,c,c+len) {
            if (g[i][j] != g[r][c]) {
                return false;
            }
        }
    }
    return true;
}

void build(Node* node, int r, int c, int len) {
    if (!node) throw;
    if (judgeSame(r, c, len)) {
        node->hasChild = false;
        node->color = g[r][c];
        return;
    }

    len /= 2;
    node->hasChild = true;
    rep(i,0,4) node->childs[i] = new Node();
    build(node->childs[0], r, c, len);
    build(node->childs[1], r, c+len, len);
    build(node->childs[2], r+len, c, len);
    build(node->childs[3], r+len, c+len, len);
}

void preorder(Node* node) {
    if (!node) return;
    if (!node->hasChild) printf(node->color ? "B" : "W");
    else {
        printf("Q");
        rep(i,0,4) {
            preorder(node->childs[i]);
        }
    }
}

void solve() {
    printf("%d\n", n);
    preorder(root);
    printf("\n");
}

void debugGraph() {
    rep(i,0,n) {
        rep(j,0,n) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

void debugTree(Node* node) {
    if (!node) return;
    if (node->hasChild) printf("Q 1\n");
    else printf("%c 0\n", node->color ? 'B' : 'W');
    rep(i,0,4) debugTree(node->childs[i]);
}

int main() {
    init();
    read();
    build(root, 0, 0, n);
    //debugGraph();
    //debugTree(root);
    solve();
}


