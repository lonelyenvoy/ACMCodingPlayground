/**
 * Created by LonelyEnvoy on 2017-3-19.
 * L2-002. 链表去重
 * Keywords: 水题
 */

#include <cstdio>
#include <cmath>
using namespace std;
#define MAX 100000

struct Node {
    int data;
    int next;
};

Node nodes[MAX]; // use an array to simulate the linked list for convenience
int normal[MAX]; // the addresses of normal nodes
int deleted[MAX]; // the addresses of deleted nodes
bool existed[MAX]; // judge if the abs of an integer has been inserted into the nodes[]

int main() {
    int first; // the first address
    int numberOfNodes;
    int numberOfNormalNodes = 0;
    int numberOfDeletedNodes = 0;
    scanf("%d%d", &first, &numberOfNodes);
    while (numberOfNodes--) { // read all nodes
        int address;
        scanf("%d", &address);
        scanf("%d%d", &nodes[address].data, &nodes[address].next);
    }
    // visit all nodes and push its address into normal[] or deleted[]
    for (int curr = first; curr != -1; curr = nodes[curr].next) {
        // check if an element or its abs has been inserted twice
        int value = (int)abs(nodes[curr].data);
        if (!existed[value]) {
            normal[numberOfNormalNodes++] = curr; // store this address to normal[]
            existed[value] = true;
        } else {
            deleted[numberOfDeletedNodes++] = curr; // store this address to deleted[]
        }
    }
    // output normal nodes
    for (int i = 0; i < numberOfNormalNodes; i++) {
        printf("%05d %d ", normal[i], nodes[normal[i]].data);
        if (i != numberOfNormalNodes - 1) {
            printf("%05d\n", normal[i + 1]);
        } else { // output the next address as -1 for the last element
            printf("-1\n");
        }
    }
    // output deleted nodes
    for (int i = 0; i < numberOfDeletedNodes; i++) {
        printf("%05d %d ", deleted[i], nodes[deleted[i]].data);
        if (i != numberOfDeletedNodes - 1) {
            printf("%05d\n", deleted[i + 1]);
        } else {
            printf("-1\n");
        }
    }
}