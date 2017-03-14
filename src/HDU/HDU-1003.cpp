/**
 * Created by LonelyEnvoy on 2017-3-14.
 * Max Sum
 * Keywords: 动态规划
 * Limits: 不能用暴力求解
 */

#include <cstdio>
using namespace std;

int main() {
    int sum;
    int maxSum;
    int start; // 当前最大子序列起始位置
    int end; // 当前最大子序列结束位置
    int lastStart; // 上一个最大子序列起始位置
    int currentInput; // 当前读入的数字

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        // init
        sum = 0;
        maxSum = -1001;
        start = end = 0;
        lastStart = 1;

        int numbers;
        scanf("%d", &numbers);
        for (int j = 0; j < numbers; j++) {

            // read
            scanf("%d", &currentInput);

            // parse
            sum += currentInput;
            if (sum > maxSum) {
                maxSum = sum;
                start = lastStart;
                end = j + 1; // current position
            }
            if (sum < 0) { // encounter a negative number, stop!
                sum = 0; // reset
                lastStart = j + 2; // next position
            }
        }

        printf("Case %d:\n%d %d %d\n", i + 1, maxSum, start, end);
        if (i != cases - 1) {
            printf("\n"); // an empty line between line
        }
    }
}