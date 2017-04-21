/**
 * Created by LonelyEnvoy on 2017-4-21.
 * Count the Colors
 * Keywords: 线段树
 */

// 线段树的具体实现细节很容易出错，详见注释

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

struct Node {
    int l, r, c;
    void set(int l, int r, int c) {
        this->l = l;
        this->r = r;
        this->c = c;
    }
};

Node tree[4 * MAX + 5];
int colors[MAX + 1]; // 第 i 个元素表示 [i, i+1] 段上的颜色值
int counts[MAX + 1]; // 第 i 个元素表示颜色值为 i 的颜色出现的次数

void build(int index, int left, int right) {
    if (left == right - 1) { // 到叶子节点时回退，还需做叶子节点的初始化
        tree[index].set(left, right, -1);
        return;
    }
    tree[index].set(left, right, -1);
    int mid = (left + right) >> 1;
    build(index << 1, left, mid);
    build((index << 1) | 1, mid, right);
}

inline void init() {
    memset(colors, -1, sizeof(colors));
    memset(counts, 0, sizeof(counts));
    build(1, 0, MAX);
}

// pushdown 的不良实现（效率低）
// 该实现的原理是，当 paint 过程中遇到非空颜色的结点 a 时，记录下结点的下标和原颜色 c 、即将要在子树中插入的颜色 d
// paint 完所有目标节点回溯到 a 时，执行 pushdown 操作，
// 到 a 的所有子树中寻找颜色为空（但未被 paint 访问过，防止破坏访问标记）的结点，将其置为颜色 c
// 如果遇到颜色为 d 的结点，则该子树的遍历结束，回退
// 这种实现方式在最坏情况下需要遍历所有子树，效率比正常方法慢 3 倍以上
/*
void pushdown(int index, int pushColor, int invadedColor) {
    if (tree[index].c == invadedColor) {
        return;
    }
    if (tree[index].l == tree[index].r - 1 || tree[index].c != -2) {
        tree[index].c = pushColor;
        return;
    }

    pushdown(index << 1, pushColor, invadedColor);
    pushdown((index << 1) | 1, pushColor, invadedColor);
}
*/

void paint(int index, int left, int right, int low, int high, int color) {
    if (left <= low && right >= high) {
        tree[index].c = color;
        return;
    }

    if (tree[index].c == color) { // 缺少这个语句会导致对相同颜色不必要的pushdown，降低线段树的查询效率
        return;
    }

    int pushColor = -1;
    if (tree[index].c >= 0) {
        //pushColor = tree[index].c; // 记录下原颜色，用于在回溯时调用 pushdown（不良实现）
        tree[index << 1].c = tree[(index << 1) | 1].c = tree[index].c; // pushdown 的正确实现：只需要将原颜色拷贝到左结点和右结点即可
    }
    tree[index].c = -2; // 将该节点的颜色标记为已分裂

    int mid = (low + high) >> 1;
    if (left < mid) { // 注意：这里易错写为 right <= mid，这将导致永远只访问左子树
        paint(index << 1, left, right, low, mid, color);
    }
    if (right > mid) { // 注意：这里易错写为 left >= mid，这将导致永远只访问右子树
        paint((index << 1) | 1, left, right, mid, high, color);
    }

    /*
    if (pushColor != -1) {
        pushdown(index, pushColor, color);
    }
    */
}

// 统计颜色段的正确实现，开始时使用了在中序序列中对不重复相邻元素计数的错误方法
// 上述错误方法会导致遍历所有子树，而不是遇到颜色立即停止，遇到一些子结点中存在但父结点已经被刷新的颜色之后统计出错
// 正确实现是在遍历遇到有颜色的结点时立即停止，并在一个数组中刷新某个颜色段的颜色
void calColorSeg(int index, int left, int right) {
    if (tree[index].c >= 0) {
        rep(i,left,right) { // 注意：这里易错写为对[left, right] 遍历，会导致 colors 数组的颜色记录错误，因为 colors 第 i 个元素表示 [i, i+1] 段上的颜色值
            colors[i] = tree[index].c;
        }
        return;
    }
    if (left == right || tree[index].c == -1) return; // 注意：遇到叶子结点和完全无颜色结点时停止！防止访问到该结点下已经被覆盖的颜色
    int mid = (left + right) >> 1;
    calColorSeg(index << 1, left, mid);
    calColorSeg((index << 1) | 1, mid, right);
}

void countColors() {
    int last;
    int curr = -1;
    erep(i,0,MAX) {
        last = curr;
        curr = colors[i];
        if (curr != -1 && curr != last) {
            counts[curr]++;
        }
    }
}

// for debug
void print(int i) {
    if (tree[i].l == tree[i].r - 1) {
        if (tree[i].c >= 0) {
            printf("%d %d %d\n", tree[i].l, tree[i].r, tree[i].c);
        }
        return;
    }

    print(i << 1);
    if (tree[i].c >= 0) {
        printf("%d %d %d\n", tree[i].l, tree[i].r, tree[i].c);
    }
    print((i << 1) | 1);
}

int main() {
    int segs;
    int l,r,c;
    while (~scanf("%d", &segs)) {
        init();
        while (segs--) {
            scanf("%d%d%d", &l, &r, &c);
            paint(1, l, r, 0, MAX, c);
            //print(1);
        }
        calColorSeg(1, 0, MAX);
        countColors();
        erep(i,0,MAX) {
            if (counts[i]) {
                printf("%d %d\n", i, counts[i]);
            }
        }
        printf("\n");
    }
}
