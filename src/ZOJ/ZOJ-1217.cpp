/**
 * Created by LonelyEnvoy on 2017-3-23.
 * Eight
 * Keywords: dfs/bfs，迷宫，最短路径
 * Limits: High run-time efficiency required 需要使用set/map/哈希存储已找到的结点，并从终点向起点找
 */

#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int posDelta[4] = {
        -3, 1, 3, -1
};

map<string, string> stateMap;

const string goalState = "12345678x";
string startState;

inline void swap(char& c1, char& c2) {
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void bfs() {
    queue<string> q;
    q.push(goalState);
    stateMap.insert(pair<string, string>(goalState, goalState));

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        // find x
        int xPos;
        for (xPos = 0; xPos < 9; xPos++) {
            if (curr[xPos] == 'x') {
                break;
            }
        }

        // move x
        for (int i = 0; i < 4; i++) {
            int nextXPos;

            if (xPos % 3 != 2) { // can move right
                nextXPos = xPos + posDelta[1];
                if (nextXPos >= 0 && nextXPos <= 8) {
                    string next = curr;
                    swap(next[xPos], next[nextXPos]);
                    if (stateMap.count(next) == 0) {
                        // visit
                        stateMap.insert(pair<string, string>(next, curr));
                        q.push(next);
                    }
                }
            }
            if (xPos % 3 != 0) { // can move left
                nextXPos = xPos + posDelta[3];
                if (nextXPos >= 0 && nextXPos <= 8) {
                    string next = curr;
                    swap(next[xPos], next[nextXPos]);
                    if (stateMap.count(next) == 0) {
                        // visit
                        stateMap.insert(pair<string, string>(next, curr));
                        q.push(next);
                    }
                }
            }
            if (xPos / 3 != 0) { // can move up
                nextXPos = xPos + posDelta[0];
                if (nextXPos >= 0 && nextXPos <= 8) {
                    string next = curr;
                    swap(next[xPos], next[nextXPos]);
                    if (stateMap.count(next) == 0) {
                        // visit
                        stateMap.insert(pair<string, string>(next, curr));
                        q.push(next);
                    }
                }
            }
            if (xPos / 3 != 2) { // can move down
                nextXPos = xPos + posDelta[2];
                if (nextXPos >= 0 && nextXPos <= 8) {
                    string next = curr;
                    swap(next[xPos], next[nextXPos]);
                    if (stateMap.count(next) == 0) {
                        // visit
                        stateMap.insert(pair<string, string>(next, curr));
                        q.push(next);
                    }
                }
            }
        }
    }
}

void trace() {
    string curr = startState;
    while (stateMap[curr] != curr) {
        string next = stateMap[curr];

        // find x
        int currXPos;
        for (currXPos = 0; currXPos < 9; currXPos++) {
            if (curr[currXPos] == 'x') {
                break;
            }
        }
        int nextXPos;
        for (nextXPos = 0; nextXPos < 9; nextXPos++) {
            if (next[nextXPos] == 'x') {
                break;
            }
        }

        // output
        int delta = nextXPos - currXPos;
        if (delta == posDelta[0]) {
            printf("u");
        } else if (delta == posDelta[1]) {
            printf("r");
        } else if (delta == posDelta[2]) {
            printf("d");
        } else if (delta == posDelta[3]) {
            printf("l");
        }

        curr = stateMap[curr];
    }
}

int main() {
    bfs(); // make map
    char c;
    while (true) {
        startState = "";
        while (true) {
            if (scanf("%c", &c) == EOF) {
                goto exit;
            }
            if (c == ' ') {
                continue;
            }
            if (c == '\n' || c == '\r') {
                break;
            }
            startState += c;
        }
        if (stateMap.find(startState) == stateMap.end()) {
            printf("unsolvable\n");
        } else {
            trace();
            printf("\n");
        }
    }
    exit:
    return 0;
}