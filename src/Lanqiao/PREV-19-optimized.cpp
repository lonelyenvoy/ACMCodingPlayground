/**
 * Created by LonelyEnvoy on 2017-3-19.
 * 九宫重排
 * Keywords: bfs, queue，set/hash
 * Limits: High run-time efficiency required
 *
 * 本解法是优化版，时间效率相对于上一版本提升了5-10倍。
 *
 *
 * 心得：
 *
 * 1. C++ STL set的效率较低，可以自己编写使用合适的哈希函数构成的hash set，用双数组做模拟链表结构
 *    （详情见代码struct StateHashSet部分），大幅提高效率。
 *
 * 2. 使用memset、memcpy、memcmp等函数直接操作内存，达到很高的时间效率。
 *
 * 3. 使用STL queue或deque时，如果对front和end指针的具体位置有需求，建议自己实现而不用标准库，虽然
 *    占用更多空间（在不使用取模回填机制的情况下），但可避免自己设一个front和end变量的代码重复问题。
 *
 * 4. 【小心使用sizeof运算符】 不当的使用可能造成非预期的效果，例如：
 *    int states[MAX_SIZE]; int state1, state2;
 *    memcmp(state1, state2, sizeof(states)) == 0 永远返回false，因为使用了错误的类型，比较了不应访问的空间。
 *    建议直接使用sizeof(int) * MAX_SIZE的格式，确保安全。
 *
 * 5. 不要将容量极大的数组放在struct或class中（大于几十万），会造成栈溢出。设置为静态成员或放在全局空间即可，或动态分配。
 *
 * 6. 不要使用形如 a[i++] = i 这样的表达式，可读性很差，而且可能造成非预期的结果。
 *
 * 7. 注意考虑问题是否一定有解。
 *
 * 8. 在debug出错时仔细检查拼写错误和逻辑错误。
 *
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define HASH_SIZE 1000000
#define MAX_SIZE 1000000

typedef int State[9];

const int positionDelta[2][4] = {
        -1, 0, 1, 0,
        0, 1, 0, -1
};

State startState;
State goalState;

State states[MAX_SIZE]; // all states are stored here
int steps[MAX_SIZE]; // stores all step of every state from the startState
int stateIndexQueue[MAX_SIZE]; // stores the bfs queue (only index of state is logged)
int front; // the front of stateIndexQueue
int rear; // the rear of stateIndexQueue

// public member of StateHashSet
int heads[HASH_SIZE]; // 存放在全局空间，防止由于数组过长导致栈溢出
int nexts[MAX_SIZE];

struct StateHashSet { // a set of states

    inline void init() {
        memset(heads, 0, sizeof(heads));
        memset(nexts, 0, sizeof(nexts));
    }

    int getHashCode(const State& s) {
        int code = 0;
        for (int i = 0; i < 9; i++) {
            code = code * 10 + s[i];
        }
        return code % HASH_SIZE;
    }

    bool insert(int index) {
        int hashCode = getHashCode(states[index]);
        int next = heads[hashCode];
        while (next) { // loop when there is a next element
            if (memcmp(states[next], states[index], sizeof(State)) == 0) {
                // the element is already inserted
                return false;
            }
            next = nexts[next];
        }
        nexts[index] = heads[hashCode];
        heads[hashCode] = index;
        return true;
    }
};

inline bool isPositionValid(int x, int y) {
    return x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

bool bfs() {

    // init steps (each state's step from the starting state)
    memset(steps, 0, sizeof(steps));

    // init stateIndexQueue (bfs queue, only index inside instead of the whole state)
    front = rear = 1;
    stateIndexQueue[rear++] = 1; // insert state 1

    // init stateSet (used to judge if an element has been visited
    StateHashSet stateSet;
    stateSet.init();
    stateSet.insert(1);

    while (front < rear) {
        int curr = stateIndexQueue[front++]; // peek and pop an index from queue

        if (memcmp(states[curr], goalState, sizeof(State)) == 0) { // reach goal, stop
            return true; // succeed
        }

        // find where the blank is
        int zeroPosition;
        for (zeroPosition = 0; zeroPosition < 9; zeroPosition++) {
            if (states[curr][zeroPosition] == 0) {
                break;
            }
        }
        int zeroX = zeroPosition / 3;
        int zeroY = zeroPosition % 3;

        // continue traversing
        State nextState;
        for (int i = 0; i < 4; i++) {
            // create next state
            memcpy(nextState, states[curr], sizeof(State));

            // define where the zero goes
            int newZeroX = zeroX + positionDelta[0][i];
            int newZeroY = zeroY + positionDelta[1][i];
            int newZeroPosition = newZeroX * 3 + newZeroY;


            if (isPositionValid(newZeroX, newZeroY)) { // continue only when new point is valid

                // switch the place of zero and normal number
                nextState[zeroPosition] = states[curr][newZeroPosition];
                nextState[newZeroPosition] = 0;

                // put nextState into states
                memcpy(states[rear], nextState, sizeof(State));
                if (stateSet.insert(rear)) { // try inserting a new point into set
                    stateIndexQueue[rear] = rear; // if succeed (not visited), add it into the queue too
                    rear++;
                    steps[rear] = steps[front] + 1; // one more step
                }
            }
        }
    }
    return false; // failed
}

int main() {

    // read
    for (int i = 0; i < 9; i++) {
        char c;
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
            i--;
            continue;
        } else if (c == '.') {
            c = '0';
        }
        startState[i] = c - '0';
    }
    for (int i = 0; i < 9; i++) {
        char c;
        scanf("%c", &c);
        if (c == '\n' || c == '\r') {
            i--;
            continue;
        } else if (c == '.') {
            c = '0';
        }
        goalState[i] = c - '0';
    }

    // init states
    memcpy(states[1], startState, sizeof(State));

    // parse and output
    if (bfs()) {
        printf("%d\n", steps[front]);
    } else {
        printf("-1\n");
    }
}