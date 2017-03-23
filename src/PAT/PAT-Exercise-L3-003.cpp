/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L3-003. 社交集群
 * Keywords: 并查集
 */

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 1001

int ufset[MAX];

inline void initUFSet() {
    memset(ufset, -1, sizeof(int) * MAX);
}

int unionUFSet(int element1, int element2) {
    while (ufset[element1] >= 0) { // find root
        element1 = ufset[element1];
    }
    while (ufset[element2] >= 0) {
        element2 = ufset[element2];
    }

    ufset[element1] += ufset[element2];
    ufset[element2] = element1;
}

int findUFSet(int data) {
    while (ufset[data] >= 0) {
        data = ufset[data];
    }
    return data;
}

void pathCollapse(int data) {
    int root = ufset[data];
    while (root >= 0 && ufset[root] >= 0) {
        root = ufset[root];
    }
    ufset[data] = root;
}

int main() {
    initUFSet();
    bool visit[MAX];
    int users[MAX];
    memset(visit, false, sizeof(bool) * MAX);
    memset(users, 0, sizeof(int) * MAX);

    int T;
    int R;
    int interest[MAX];
    scanf("%d", &T);
    int insertPos;
    for (int i = 0; i < T; i++) {
        scanf("%d:", &R);
        insertPos = -1;
        for (int j = 0; j < R; j++) {
            scanf("%d", interest + j);
            visit[interest[j]] = true;
            if (ufset[ interest[j] ] < 0 && ufset[j] != -1 && visit[ufset[j]]) {
                insertPos = j;
            }
        }
        if (insertPos == -1) {
            insertPos = 0;
        }
        for (int j = 0; j < R; j++) {
            if (insertPos != j) {
                unionUFSet(interest[insertPos], interest[j]);
//				printf("insert: %d %d\n",interest[insertPos], interest[j]);
            }
        }
        int curr = interest[0];
        while (ufset[curr] >= 0) {
            curr = ufset[curr];
        }
        users[curr]++;
    }

    // statistics
    int setCount = 0;
    for (int i = 0; i < MAX; i++) {
        if (visit[i]) {
            pathCollapse(i);
            if (ufset[i] < 0) {
                setCount++;
            }
        }
    }

    // resign users count
    int userOfSets[MAX];
    memset(userOfSets, 0, sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++) {
        if (users[i] > 0) {
            userOfSets[findUFSet(i)] += users[i];
        }
    }

    // sort
    priority_queue<int, vector<int>, less<int> > sortedUser;
    for (int i = 0; i < MAX; i++) {
        if (userOfSets[i] > 0/* && ufset[i] < 0*/) {
            sortedUser.push(userOfSets[i]);
        }
    }


    // output
    printf("%d\n", setCount);
    bool first = true;
    while (!sortedUser.empty()) {
        if (!first) {
            printf(" ");
        } else {
            first = false;
        }
//			printf("%d:", i);
        printf("%d", sortedUser.top());
        sortedUser.pop();
    }
    printf("\n");
}