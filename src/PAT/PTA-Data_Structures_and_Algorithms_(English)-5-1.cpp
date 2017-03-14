/**
 * Created by LonelyEnvoy on 2017-3-14.
 * 5-1 Maximum Subsequence Sum
 * Keywords: 动态规划，与HDU 1003类似
 * Limits: 不能用暴力求解
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define MAX 10001

struct Position {
    int start;
    int end;

    Position(int _start, int _end) : start(_start), end(_end) {}
};

bool operator<(const Position& p1, const Position& p2) {
    return p1.start > p2.start ? true : p1.end > p2.end;
}

int main() {
    int sum = 0;
    int maxSum = numeric_limits<int>::min();
    int lastStart = 0; // 上一个最大子序列起始位置
    int currentInput; // 当前读入的数字

    int data[MAX]; // 所有数字

    priority_queue<Position> positionQueue; // maxSum相同时，存储所有最大子序列的起始位置和结束位置，下标小的排在前面

    int numbers;
    scanf("%d", &numbers);
    for (int j = 0; j < numbers; j++) {

        // read
        scanf("%d", &currentInput);
        data[j] = currentInput;

        // parse
        sum += currentInput;
        if (sum >= maxSum) {
            if (maxSum != sum) {
                // clear queue
                while (!positionQueue.empty()) {
                    positionQueue.pop();
                }
            }
            maxSum = sum;
            positionQueue.push(Position(lastStart, j));
        }

        if (sum < 0) { // encounter a negative number, stop!
            sum = 0; // reset
            lastStart = j + 1; // next position
        }
    }

    if (maxSum < 0) { // all inputs are negative
        printf("%d %d %d\n", 0, data[0], data[numbers - 1]);
    } else {
        printf("%d %d %d\n", maxSum, data[positionQueue.top().start], data[positionQueue.top().end]);
    }
}
