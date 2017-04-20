/**
 * Created by LonelyEnvoy on 2017-4-20.
 * Double Queue
 * Keywords: Splay Tree的简单应用，水题
 */

// 本题用普通BST比Splay Tree更快，可能是由于题目数据规模较小

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

struct Node {
    int data;
    int weight;
    Node* child[2];
    Node* parent;

    Node(int data, int weight, Node* child0, Node* child1, Node* parent) {
        this->data = data;
        this->weight = weight;
        this->child[0] = child0;
        this->child[1] = child1;
        this->parent = parent;
    }
};

Node* root;

// 以下两个zig zag函数可以合并为一个
void zig(Node* x) {
    Node* y;
    Node* z;
    if (!x || !(y = x->parent)) return;
    z = y->parent;

    x->parent = z;
    y->parent = x;
    if (x->child[1]) {
        x->child[1]->parent = y;
    }
    y->child[0] = x->child[1];
    x->child[1] = y;
    if (z) {
        (z->child[0] == y) ? (z->child[0] = x) : (z->child[1] = x);
    } else {
        root = x;
    }
}

void zag(Node* x) {
    Node* y;
    Node* z;
    if (!x || !(y = x->parent)) return;
    z = y->parent;

    y->parent = x;
    x->parent = z;
    if (x->child[0]) {
        x->child[0]->parent = y;
    }
    y->child[1] = x->child[0];
    x->child[0] = y;
    if (z) {
        (z->child[0] == y) ? (z->child[0] = x) : (z->child[1] = x);
    } else {
        root = x;
    }
}

void splay(Node* x) {
    Node* y;
    Node* z;
    if (!x || !(y = x->parent)) return;
    z = y->parent;

    if (!z) {
        (x == y->child[0]) ? zig(x) : zag(x);
    } else {
        if (y->child[0] == x) {
            if (z->child[0] == y) {
                zig(y);
                zig(x);
            } else {
                zig(x);
                zag(x);
            }
        } else {
            if (z->child[1] == y) {
                zag(y);
                zag(x);
            } else {
                zag(x);
                zig(x);
            }
        }
    }
    splay(x->parent);
}

bool insert(int data, int weight) {
    Node* p = root;
    Node* q = NULL;
    while (p) {
        q = p;
        if (weight == p->weight) return false;
        else if (weight < p->weight) p = p->child[0];
        else p = p->child[1];
    }
    p = new Node(data, weight, NULL, NULL, q);
    if (q) {
        q->child[weight < q->weight ? 0 : 1] = p;
        splay(p);
    } else {
        root = p;
    }
    return true;
}

void remove(Node* p) {
    if (!p) return;
    Node* q = p->parent;
    if (!p->child[0] && !p->child[1]) {
        if (q) {
            (q->child[0] == p) ? (q->child[0] = NULL) : (q->child[1] = NULL);
        } else {
            root = NULL;
        }
        delete p;
    } else if (p->child[0] && !p->child[1]) {
        if (q) {
            (q->child[0] == p) ? (q->child[0] = p->child[0]) : (q->child[1] = p->child[0]);
        } else {
            root = p->child[0];
        }
        p->child[0]->parent = q;
        delete p;
    } else if (!p->child[0] && p->child[1]) {
        if (q) {
            (q->child[0] == p) ? (q->child[0] = p->child[1]) : (q->child[1] = p->child[1]);
        } else {
            root = p->child[1];
        }
        p->child[1]->parent = q;
        delete p;
    } else {
        Node* r = p->child[1];
        while (r->child[0]) {
            r = r->child[0];
        }

        p->data = r->data;
        p->weight = r->weight;
        (r->parent->child[0] == r)
            ? (r->parent->child[0] == r->child[1])
            : (r->parent->child[1] == r->child[1]);
        if (r->child[1]) {
            r->child[1]->parent = r->parent;
        }
        delete r;
    }
}

// flag = 0 -> drop low, flag = 1 -> drop high
// returns dropped data
// if unable to drop (null tree), returns -1
int drop(int flag) {
    Node* p = root;
    if (!p) return -1;
    while (p->child[flag]) {
        p = p->child[flag];
    }
    Node* q = p->parent;
    int data = p->data;
    remove(p);
    splay(q);
    return data;
}

bool search(int weight) {
    Node* p = root;
    while (p) {
        if (weight == p->weight) {
            splay(p);
            return true;
        }
        else if (weight < p->weight) p = p->child[0];
        else p = p->child[1];
    }
    splay(p);
    return false;
}

int main() {
    int op, k, p;
    while (~scanf("%d", &op) && op) {
        switch(op) {
        case 1:
            scanf("%d%d", &k, &p);
            insert(k, p);
            break;
        case 2:
            root ? printf("%d\n", drop(1)) : printf("0\n");
            break;
        case 3:
            root ? printf("%d\n", drop(0)) : printf("0\n");
            break;
        }
    }
}
