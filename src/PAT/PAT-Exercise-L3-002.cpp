/**
 * Created by LonelyEnvoy on 2017-3-20.
 * L3-002. 堆栈
 * Keywords: 线段树
  * Limits: High run-time efficiency required
 */

#include <cstdio>
#include <stack>
using namespace std;

#define MAX 100000

// --- Segment Tree ---
// Storing the number of valid numbers in [left, right)

int tree[4 * MAX + 1];

void createTree(int node, int begin, int end) {
    if (begin == end) {
        tree[node] = 0;
        return;
    }

    int mid = (begin + end) >> 1;
    createTree(node << 1, begin, mid);
    createTree((node << 1) + 1, mid + 1, end);
}

void updateNode(int node, int begin, int end, int index, int delta) {
    if (begin == end) {
        tree[node] += delta;
        return;
    }

    int mid = (begin + end) >> 1;
    if (index <= mid) {
        updateNode(node << 1, begin, mid, index, delta);
    } else {
        updateNode((node << 1) + 1, mid + 1, end, index, delta);
    }

    // update parent node
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int queryKthBiggestNum(int node, int left, int right, int k) {

    if (left == right) {
        return left;
    }

    int mid = (left + right) >> 1;
    if (tree[node << 1] >= k) { // median in left subtree
        return queryKthBiggestNum(node << 1, left, mid, k);
    } else { // median in right subtree
        return queryKthBiggestNum((node << 1) + 1, mid + 1, right, k - tree[node << 1]);
    }
}
// --- Segment Tree ---

int main() {
//    // 测试样例
//    createTree(1, 1, 5);
//    updateNode(1, 1, 5, 1, 1);
//    updateNode(1, 1, 5, 2, 1);
//    updateNode(1, 1, 5, 3, 2);
//    updateNode(1, 1, 5, 4, 1);
//
//    int result = queryKthBiggestNum(1, 1, 5, 6/2);
//    printf("%d\n", result);

    createTree(1, 1, MAX);
    stack<int> s;

    int T;
    char directive[11];
    int operand;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", directive);
        switch (directive[1]) {
            case 'u': // push
                scanf("%d", &operand);
                s.push(operand);
                updateNode(1, 1, MAX, operand, 1);
                break;
            case 'o': // pop
                if (s.empty()) {
                    printf("Invalid\n");
                } else {
                    operand = s.top();
                    s.pop();
                    updateNode(1, 1, MAX, operand, -1);
                    printf("%d\n", operand);
                }
                break;
            case 'e': // peekMedian
                if (s.empty()) {
                    printf("Invalid\n");
                } else {
                    int evenSize = s.size();
                    if (evenSize % 2 != 0) {
                        evenSize++;
                    }
                    printf("%d\n", queryKthBiggestNum(1, 1, MAX, evenSize >> 1));
                }
                break;
        }
    }
}
