/**
 * Created by LonelyEnvoy on 2017-3-30.
 * Quad Trees
 * Keywords: implementation，四分树，dfs
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
#define minof(x, y) (x) < (y) ? (x) : (y)
#define maxof(x, y) (y) < (x) ? (x) : (y)

const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 512
// end of header


struct Node {
    bool hasChildren;
    bool value;
    Node* child[4];
};

bool figure[MAX][MAX];

bool judgeEqual(int x1, int y1, int x2, int y2) {
    bool first = figure[x1][y1];
    erep(i, x1, x2) {
        erep(j, y1, y2) {
            if (figure[i][j] != first) {
                return false;
            }
        }
    }
    return true;
}

void createTree(Node* root, int x1, int y1, int x2, int y2) {
    if (judgeEqual(x1, y1, x2, y2)) {
        root->hasChildren = false;
        root->value = figure[x1][y1];
    } else {
        root->hasChildren = true;
        rep(i, 0, 4) {
            root->child[i] = new Node();
        }
        const int midx = (x1 + x2) / 2;
        const int midy = (y1 + y2) / 2;
        createTree(root->child[0], x1, y1, midx, midy);
        createTree(root->child[1], x1, midy + 1, midx, y2);
        createTree(root->child[2], midx + 1, y1, x2, midy);
        createTree(root->child[3], midx + 1, midy + 1, x2, y2);
    }
}

void encode(Node* root, deque<bool>& code) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        // visit
        code.push_back(curr->hasChildren);
        if (!curr->hasChildren) {
            code.push_back(curr->value);
        } else {
            rep(i, 0, 4) {
                q.push(curr->child[i]);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int buffer;
        rep(i, 0, n) {
            rep(j, 0, n) {
                scanf("%d", &buffer);
                figure[i][j] = buffer;
            }
        }
        Node* root = new Node();
        createTree(root, 0, 0, n-1, n-1);
        deque<bool> code;
        encode(root, code);
        // calculate hex
        int sum = 0;
        while (!code.empty()) {
            bool value = code.front();
            code.pop_front();
            sum = (sum << 1) + value;
        }
        printf("%0X\n", sum);
    }
    return 0;
}
