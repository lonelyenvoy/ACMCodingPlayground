/**
 * Created by LonelyEnvoy on 2017-3-16.
 * Exchange Cards
 * Keywords: dfs
 * Limits: 需剪枝或用哈希法提高效率（如代码所示）
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 1001

int cards[MAX]; // index -> value of card, value -> amount of cards with this value
int cardKinds;
int maxCardNumber;
int expectedValue;

int sum;
int solutionCount;

void dfs(int start) {
    if (sum == expectedValue) {
        solutionCount++;
        return;
    }
    for (int i = start; i <= maxCardNumber; i++) {
        if (cards[i] > 0 && sum + i <= expectedValue) {
            cards[i]--;
            sum += i;
            dfs(i);
            cards[i]++;
            sum -= i;
        }
    }
}

int main() {
    int index;
    bool isFirstCase = true;
    while (scanf("%d%d", &expectedValue, &cardKinds) == 2) {
        // init
        memset(cards, 0, sizeof(int) * MAX);
        sum = 0;
        solutionCount = 0;
        maxCardNumber = 0;

        // read
        while (cardKinds--) {
            scanf("%d", &index);
            scanf("%d", cards + index);
            if (index > maxCardNumber) {
                maxCardNumber = index;
            }
        }

        // parse
        dfs(1);

        // output
        if (!isFirstCase) {
            printf("\n");
        }
        isFirstCase = false;
        printf("%d\n", solutionCount);
    }
}
