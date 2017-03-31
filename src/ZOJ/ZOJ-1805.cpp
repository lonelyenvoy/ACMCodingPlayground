/**
 * Created by LonelyEnvoy on 2017-3-31.
 * Squadtrees
 * Keywords: implementation，四分树，dfs/bfs
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
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

#define rep(i, a, n) for (int i = a; i < n; i++)
#define erep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define minof(x, y) (((x) < (y)) ? (x) : (y))
#define maxof(x, y) (((y) < (x)) ? (x) : (y))

const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 128
// end of header

#define MAX_HASH 100000

struct Node {
    bool hasChild;
    int value;
    Node* child[4];
};

bool judgeEqualNode(const Node* n1, const Node* n2) {
    if ((!n1->hasChild && n2->hasChild) || (n1->hasChild && !n2->hasChild)) {
        return false;
    }
    if (!n1->hasChild && !n2->hasChild) {
        return n1->value == n2->value;
    }
    rep(i, 0, 4) {
        if (!judgeEqualNode(n1->child[i], n2->child[i])) {
            return false;
        }
    }
    return true;
}

bool bmp[MAX][MAX];
vector<Node*> hashSet[MAX_HASH];

// --- hashSet ---

int hashCode(Node* node) {
    if (!node->hasChild) {
        return node->value;
    } else {
        int code = 0;
        rep(i, 0, 4) {
            code = ((code << 1) + hashCode(node->child[i])) % MAX_HASH;
        }
        return code % MAX_HASH;
    }
}

bool existSet(Node* node, int hashcode) {
    vector<Node*> unit = hashSet[hashcode];
    if (unit.empty()) {
        return false;
    } else {
        int size = sz(unit);
        rep(i, 0, size) {
            if (judgeEqualNode(unit[i], node)) {
                return true;
            }
        }
        return false;
    }
}

bool insertSet(Node* node) {
    int code = hashCode(node);
    if (existSet(node, code)) {
        return false;
    } else {
        hashSet[code].pb(node);
        return true;
    }
}

// unsafe
Node* findSet(Node* node, int hashcode) {
    vector<Node*> unit = hashSet[hashcode];
    int size = sz(unit);
    rep(i, 0, size) {
        if (judgeEqualNode(unit[i], node)) {
            return unit[i];
        }
    }
    return NULL;
}

// --- hashSet ends ---

bool judgeEqual(int x1, int y1, int x2, int y2) {
    bool first = bmp[x1][y1];
    erep(i, x1, x2) {
        erep(j, y1, y2) {
            if (bmp[i][j] != first) {
                return false;
            }
        }
    }
    return true;
}

void createQuadTree(Node* root, int x1, int y1, int x2, int y2) {
    if (judgeEqual(x1, y1, x2, y2)) {
        root->hasChild = false;
        root->value = bmp[x1][y1];
    } else {
        root->hasChild = true;
        rep(i, 0, 4) {
            root->child[i] = new Node();
        }
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;
        createQuadTree(root->child[0], x1, y1, midx, midy);
        createQuadTree(root->child[1], x1, midy + 1, midx, y2);
        createQuadTree(root->child[2], midx + 1, y1, x2, midy);
        createQuadTree(root->child[3], midx + 1, midy + 1, x2, y2);
    }
}

void superizeTree(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        // visit
        if (node->hasChild) {
            rep(i, 0, 4) {
                Node*& child = node->child[i];
                Node* oldNode = findSet(child, hashCode(child));
                if (oldNode == NULL || !child->hasChild) {
                    insertSet(child);
                } else {
                    // modify pointer
                    child = oldNode;
                }
            }
        }

        if (node->hasChild) {
            rep(i, 0, 4) {
                q.push(node->child[i]);
            }
        }
    }
}

int countNodes(Node* root) {
    queue<Node*> q;
    set<Node*> visited;
    q.push(root);

    int count = 0;
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (visited.count(node) == 0) {
            visited.insert(node);
            count++;
        }
        if (node->hasChild) {
            rep(i, 0, 4) {
                q.push(node->child[i]);
            }
        }
    }
    return count;
}

int main() {
    while (true) {

        // init
        memset(bmp, false, sizeof(bmp));
        rep(i, 0, MAX_HASH) {
            hashSet[i].clear();
        }

        // read
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0) {
            break;
        }
        char buffer;
        rep(i, 0, x) {
            rep(j, 0, y) {
                scanf("%c", &buffer);
                if (buffer == '\n' || buffer == '\r') {
                    j--;
                    continue;
                }
                bmp[i][j] = buffer == '1';
            }
        }
        int n = (1 << (int) ceil(log(maxof(x, y)) / log(2)));

        // fill 0
        rep(i, x, n) {
            rep(j, 0, n) {
                bmp[i][j] = false;
            }
        }
        rep(i, 0, n) {
            rep(j, y, n) {
                bmp[i][j] = false;
            }
        }

        // parse
        Node *root = new Node();
        createQuadTree(root, 0, 0, n - 1, n - 1);
        int preCount = countNodes(root);
        superizeTree(root);
        int currCount = countNodes(root);
        printf("%d %d\n", preCount, currCount);
    }
}
