/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L3-010. 是否完全二叉搜索树
 * Keywords: 二叉树的bfs遍历
 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int* tree;

void insert(int data, int index) {
    while (true) {
        if (tree[index] == 0) {
            tree[index] = data;
            return;
        }
        if (data > tree[index]) {
            index = 2 * index + 1; // goto left subtree
        } else {
            index = 2 * index + 2; // goto right subtree
        }
    }
}

// return if the tree is a complete binary tree
bool traverseLevelOrderAndJudgeIsCompleteBinTree(int n) {
    queue<int> visitQueue;
    visitQueue.push(0);

    int pos;
    int count = 0;
    bool isCompleteBinTree = true;
    while (!visitQueue.empty()) {
        pos = visitQueue.front();
        visitQueue.pop();
        // visit
        if (tree[pos] != 0) {
            cout << tree[pos];
            if (++count < n) {
                cout << " ";
            }

            visitQueue.push(2 * pos + 1);
            visitQueue.push(2 * pos + 2);
        } else if (pos < n) {
            isCompleteBinTree = false;
        }
    }
    cout << endl;
    return isCompleteBinTree;
}

int main() {
    int N;
    cin >> N;

    const int maxNodes = 1048576; // 2^20
    tree = new int[maxNodes];
    memset(tree, 0, sizeof(int) * maxNodes);

    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        insert(data, 0);
    }

    // output level order traverse sequence
    cout << (traverseLevelOrderAndJudgeIsCompleteBinTree(N) ? "YES" : "NO") << endl;
    delete[] tree;
}
