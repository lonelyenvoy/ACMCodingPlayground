/**
 * Created by LonelyEnvoy on 2017-3-11.
 * Tree
 * Keywords: 二叉树
 *
 */

#include <iostream>
#include <stack>
#include <deque>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int _data = 0, Node* _leftChild = NULL, Node* _rightChild = NULL)
            : data(_data), leftChild(_leftChild), rightChild(_rightChild) {}
};

void createBinTree(int* inOrderList, int* postOrderList, int n, Node*& root) {
    // create finished
    if (n == 0) {
        return;
    }

    // find the root node in inOrderList
    int rootPos;
    for (int i = 0; i < n; i++) {
        if (inOrderList[i] == postOrderList[n - 1]) {
            rootPos = i;
        }
    }

    // create root node
    root = new Node(inOrderList[rootPos]);

    // create left subTree
    createBinTree(inOrderList, postOrderList, rootPos, root->leftChild);
    // create right subTree
    createBinTree(inOrderList + rootPos + 1, postOrderList + rootPos, n - rootPos - 1, root->rightChild);
}

void printBinTree(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printBinTree(root->leftChild);
    printBinTree(root->rightChild);
}

int findMinWeightLeaf(Node* root) {
    stack<Node*> visitStack;
    visitStack.push(root);

    Node* node;
    deque<Node*> traceQueue;
    deque<Node*> minTraceQueue;
    int minWeight = numeric_limits<int>::max();
    // traverse preorder
    while (!visitStack.empty()) {
        node = visitStack.top();
        visitStack.pop();
        traceQueue.push_back(node);
        // visit
        if (node->leftChild == NULL && node->rightChild == NULL) {
            // calculate sum weight
            int sumWeight = 0;
            for (deque<Node*>::iterator itr = traceQueue.begin(); itr != traceQueue.end(); ++itr) {
                sumWeight += (*itr)->data;
            }
            // if found a less weighted leaf node, update the min queue
            if (sumWeight < minWeight
                || (sumWeight == minWeight && traceQueue.back()->data < minTraceQueue.back()->data)) {
                minWeight = sumWeight;
                minTraceQueue = traceQueue;
            }
            traceQueue.pop_back(); // backtrack
        }
        if (node->rightChild) {
            visitStack.push(node->rightChild);
        }
        if (node->leftChild) {
            visitStack.push(node->leftChild);
        }
    }

    return minTraceQueue.back()->data;
}

void splitString(const string& s, char delim, vector<string>& strings) {
    size_t searchPos = 0;
    size_t length = s.length();
    while (searchPos < length) {
        size_t index = s.find_first_of(delim, searchPos);
        if (index == string::npos) {
            strings.push_back(s.substr(searchPos, length - searchPos));
            break;
        }
        strings.push_back(s.substr(searchPos, index - searchPos));
        searchPos = index + 1;
    }
}

int main() {
    Node* root;

    string line;
    vector<string> strings;
    int* values[2];
    istringstream stream;
    int numberOfInputs;
    while (true) {
        // read the inOrderList and postOrderList
        for (int i = 0; i < 2; i++) {
            // read a line
            getline(cin, line);
            if (cin.eof()) {
                goto exit;
            }

            strings.clear();

            // parse the line
            splitString(line, ' ', strings);
            numberOfInputs = strings.size();
            values[i] = new int[numberOfInputs];
            for (int j = 0; j < numberOfInputs; j++) {
                stream.clear();
                stream.str(strings[j]);
                stream >> values[i][j];
            }
        }

        // create tree
        createBinTree(values[0], values[1], numberOfInputs, root);

        // find the min weight leaf
        cout << findMinWeightLeaf(root) << endl;

        // free memory
        for (int i = 0; i < 2; i++) {
            delete[] values[i];
        }
    }
    exit:
    return 0;
}
