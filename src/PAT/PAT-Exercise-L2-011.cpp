/**
 * Created by LonelyEnvoy on 2017-3-22.
 * L2-011. 玩转二叉树
 * Keywords: 二叉树的遍历，队列的简单应用
 */

#include <cstdio>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* leftChild;
	Node* rightChild;
};

Node* root = NULL;

Node* create(int* preOrder, int* inOrder, int n) {
	if (n == 0) {
		return NULL;
	}

	int k = 0;
	while (inOrder[k] != preOrder[0]) {
		k++;
	}

	Node* node = new Node();
	node->data = preOrder[0];
	node->leftChild = create(preOrder + 1, inOrder, k);
	node->rightChild = create(preOrder + k + 1, inOrder + k + 1, n - k - 1);
	return node;
}

void outputReversedLevelOrder() {
	queue<Node*> q;
	q.push(root);

	bool first = true;
	while (!q.empty()) {
		Node* node = q.front();
		q.pop();
		if (!first) {
			printf(" ");
		}
		printf("%d", node->data);
		first = false;
		if (node->rightChild != NULL) {
			q.push(node->rightChild);
		}
		if (node->leftChild != NULL) {
			q.push(node->leftChild);
		}
	}
}

int main() {
	int n;
	int pre[30];
	int in[30];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", in + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", pre + i);
	}

	root = create(pre, in, n);
	outputReversedLevelOrder();
}
