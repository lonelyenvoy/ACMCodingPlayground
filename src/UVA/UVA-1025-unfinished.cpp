/**
 * Created by LonelyEnvoy on 2017-3-29.
 * A Spy in the Metro
 * Keywords: DP
 */

/* Unfinished! */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <limits>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define erep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define minof(x, y) (x) < (y) ? (x) : (y)
#define maxof(x, y) (y) < (x) ? (x) : (y)

//const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 10000
// end of header

#define INF 10000
#define MAX_STATS 51
#define MAX_TRAINS 50
#define MAX_TIME 201

int dp[MAX_TIME][MAX_STATS];
bool hasTrain[MAX_TIME][MAX_STATS][2];

int main() {
    int numOfStats;
    int targetTime;
    int travelTime[MAX_STATS];
    int leftTrainCount;
    int leftStartTime[MAX_TRAINS];
    int rightTrainCount;
    int rightStartTime[MAX_TRAINS];

    int elapsedLeftTravelTime[MAX_STATS];
    int elapsedRightTravelTime[MAX_STATS];

    // read
    scanf("%d%d", &numOfStats, &targetTime);
    erep(i, 1, numOfStats - 1) {
        scanf("%d", travelTime + i);
    }
    scanf("%d", &leftTrainCount);
    erep(i, 1, leftTrainCount) {
        scanf("%d", leftStartTime + i);
    }
    scanf("%d", &rightTrainCount);
    erep(i, 1, rightTrainCount) {
        scanf("%d", rightStartTime + i);
    }

    // init
    erep(i, 1, numOfStats) {
        elapsedLeftTravelTime[i] = leftStartTime[i];
        elapsedRightTravelTime[i] = rightStartTime[i];
        rep(j, 1, i) {
            elapsedLeftTravelTime[i] += travelTime[j];
            elapsedRightTravelTime[i] += travelTime[j];
        }
    }
    erep(i, 1, numOfStats) {
        hasTrain[ elapsedLeftTravelTime[i] ][i][0] = true;
        hasTrain[ elapsedRightTravelTime[i] ][i][1] = true;
    }
    erep(j, 1, numOfStats - 1) {
        dp[targetTime][j] = INF;
    }
    dp[targetTime][numOfStats] = 0;

    // dp
    per(i, 0, targetTime) {
        erep(j, 1, numOfStats) {
            // strategies: wait for 1 unit time / take a train heading for left / take ~ for right
            dp[i][j] = dp[i + 1][j] + 1;
            if (hasTrain[i][j][0] && (j + 1 <= numOfStats) && (i + travelTime[j] <= targetTime)) {
                dp[i][j] = minof(dp[i][j], dp[i + travelTime[j]][j + 1]);
            }
            if (hasTrain[i][j][1] && (j - 1 <= numOfStats) && (i + travelTime[j - 1] <= targetTime)) {
                dp[i][j] = minof(dp[i][j], dp[i + travelTime[j - 1]][j - 1]);
            }
        }
    }
    if (dp[0][1] > MAX_TIME) {
        printf("impossible\n");
    } else {
        printf("%d\n", dp[0][1]);
    }
    return 0;
}
