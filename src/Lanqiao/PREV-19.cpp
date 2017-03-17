/**
 * Created by LonelyEnvoy on 2017-3-18.
 * 九宫重排
 * Keywords: bfs, queue
 * Limits: High run-time efficiency required
 */

#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#pragma GCC optimize ("O2") // enable complier optimization
#define MAX_STEPS 1000000

struct State {
    int num[9]; // 0 is a blank block

    State() {}

    State(const State& o) {
        for (int i = 0; i < 9; i++) {
            this->num[i] = o.num[i];
        }
    }

    State& operator=(const State& o) {
        if (*this == o) return *this;
        for (int i = 0; i < 9; i++) {
            this->num[i] = o.num[i];
        }
        return *this;
    }

    bool operator==(const State& o) {
        for (int i = 0; i < 9; i++) {
            if (this->num[i] != o.num[i]) {
                return false;
            }
        }
        return true;
    }
};

bool operator<(const State& o1, const State& o2) {
    int hashCode[2] = {0, 0};
    for (int i = 0; i < 9; i++) {
        hashCode[0] = hashCode[0] * 10 + o1.num[i];
        hashCode[1] = hashCode[1] * 10 + o2.num[i];
    }
    return hashCode[0] < hashCode[1];
}

const int positionDelta[2][4] = {
        -1, 0, 1, 0,
        0, 1, 0, -1
};

State startState;
State goalState;
set<State> visitedSet;
int steps[MAX_STEPS];
int front; // simulated queue front used in bfs
int rear; // simulated queue rear used in bfs

inline bool isPositionValid(int x, int y) {
    return x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

bool bfs() {
    queue<State> visitQueue;
    visitQueue.push(startState);
    visitedSet.insert(startState);

    State curr;
    State next;
    while (!visitQueue.empty()) {
        curr = visitQueue.front();
        visitQueue.pop();

        // check if reached destination
        if (curr == goalState) {
            return true;
        }

        // find zero point (blank)
        int zeroIndex;
        for (zeroIndex = 0; zeroIndex < 9; zeroIndex++) {
            if (curr.num[zeroIndex] == 0) {
                break;
            }
        }
        int zeroX = zeroIndex / 3;
        int zeroY = zeroIndex % 3;

        // continue traversing
        int nextZeroX;
        int nextZeroY;
        int nextZeroIndex;
        for (int i = 0; i < 4; i++) {
            nextZeroX = zeroX + positionDelta[0][i];
            nextZeroY = zeroY + positionDelta[1][i];
            nextZeroIndex = nextZeroX * 3 + nextZeroY;
            if (isPositionValid(nextZeroX, nextZeroY)) {
                next = curr;
                // switch the place of zero
                next.num[zeroIndex] = next.num[nextZeroIndex];
                next.num[nextZeroIndex] = 0;
                if (visitedSet.count(next) == 0) { // not visited
                    // visit
                    steps[rear] = steps[front] + 1; // calculate step
                    rear++; // move forward
                    visitQueue.push(next);

                    // log visited
                    visitedSet.insert(next);
                }
            }
        }
        front++; // move forward
    }
    return false; // unable to reach destination
}

int main() {

    // init
    visitedSet.clear();
    memset(steps, 0, sizeof(int) * MAX_STEPS);
    front = 1; // simulated queue front used in bfs
    rear = 2; // simulated queue rear used in bfs

    // read
    char c;
    for (int i = 0; i < 9; i++) {
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
            i--;
            continue;
        }
        if (c == '.') {
            startState.num[i] = 0;
        } else {
            startState.num[i] = c - '0';
        }
    }
    for (int i = 0; i < 9; i++) {
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
            i--;
            continue;
        }
        if (c == '.') {
            goalState.num[i] = 0;
        } else {
            goalState.num[i] = c - '0';
        }
    }

    // parse and output
    if (bfs()) {
        printf("%d\n", steps[front]);
    } else {
        printf("-1\n");
    }
}
