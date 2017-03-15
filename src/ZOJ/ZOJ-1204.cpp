/**
 * Created by LonelyEnvoy on 2017-3-15.
 * Additive equations
 * Keywords: dfs
 * Limits: 需剪枝
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 30

int data[MAX];
int N;
bool visited[MAX];
bool isSolutionFound;

void dfs(int start, int length, int sum) {
    if (length == 0) { // no more number needed, stop dfs
        // try to find if there is a number == sum
        for (int i = start; i < N && sum <= data[N - 1]; i++) {
            // found solution
            if (sum == data[i]) {
                isSolutionFound = true;
                // output all visited elements
                int remainingSum = sum; // subtract the sum to judge the last element
                for (int j = 0; j < N; j++) {
                    if (visited[j]) {
                        if (remainingSum == data[j]) { // data[j] is the last element visited
                            printf("%d=%d\n", data[j], sum);
                        } else {
                            printf("%d+", data[j]);
                        }
                        remainingSum -= data[j];
                    }
                }
            }
        }
        return;
    }
    // sum <= data[N -1] is very important:  when the sum is overlarge, skip it! Without this, TLE will occur
    if (sum <= data[N - 1]) {
        for (int i = start; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sum += data[i];
                length--;
                dfs(i, length, sum);
                visited[i] = false;
                sum -= data[i];
                length++;
            }
        }
    }

}

int main() {

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        // init
        memset(visited, false, sizeof(bool) * MAX);
        isSolutionFound = false;

        // read
        scanf("%d", &N);
        int input;
        for (int j = 0; j < N; j++) {
            scanf("%d", data + j);
        }

        // parse
        sort(data, data + N);
        for (int j = 2; j < N; j++) {
            dfs(0, j, 0);
        }

        // output
        if (!isSolutionFound) {
            printf("Can't find any equations.\n\n");
        } else {
            printf("\n");
        }

    }
}
