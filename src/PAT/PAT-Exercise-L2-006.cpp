/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L2-006. 树的遍历
 * Keywords: 二叉树的dfs和bfs遍历，队列的简单应用
 */

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int _data, Node* _leftChild = NULL, Node* _rightChild = NULL)
            : data(_data), leftChild(_leftChild), rightChild(_rightChild) {}
};

void createBinTree(int* inOrder, int* postOrder, int n, Node*& root) {
    if (n == 0) {
        return;
    }
    int k;
    for (int i = 0; i < n; i++) {
        if (inOrder[i] == postOrder[n - 1]) {
            k = i;
        }
    }
    root = new Node(postOrder[n - 1]);
    createBinTree(inOrder, postOrder, k, root->leftChild);
    createBinTree(inOrder + k + 1, postOrder + k, n - k - 1, root->rightChild);
}

Node* root;

void traverLevelOrder(int n) {
    queue<Node*> visitQueue;
    visitQueue.push(root);

    int count = 0;
    while (!visitQueue.empty()) {
        Node* node = visitQueue.front();
        visitQueue.pop();
        // visit
        cout << node->data;
        if (++count < n) {
            cout << " ";
        }
        if (node->leftChild != NULL) {
            visitQueue.push(node->leftChild);
        }
        if (node->rightChild != NULL) {
            visitQueue.push(node->rightChild);
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    int* postOrder = new int[N];
    int* inOrder = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> postOrder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inOrder[i];
    }
    createBinTree(inOrder, postOrder, N, root);
    traverLevelOrder(N);
}
