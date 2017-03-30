/**
 * Created by LonelyEnvoy on 2017-3-30.
 * A Spy in the Metro
 * Keywords: DP
 */

 /*
 解题思路：动态规划。
 主要的逻辑用这两个数组实现：
 dp[time][station]
 hasTrain[time][station][trainDirection]

 踩过的坑：
 1. scanf 不能直接读入 bool 型变量。如果用 %d 读入（4个字节）会导致bool变量的接下来3个字节被覆盖，可能不出错，也可能产生段错误。危险操作！
 2. INF 在动态规划的题目中一般不能用 int 型的最大值来表示，因为某个节点的状态值可能会被增加，导致溢出变为负数。
 3. 搞清楚每个下标的范围，(0, a) (0, a] [0, a) [0, a] 很容易出错。
 4. 每次刷表（更新状态）时务必仔细检查相应的状态下标是否已经超出合理范围。
 5. 多试几组数据，避免自己考虑不到的情况发生。（最好手写随机数据产生器，目前尚在学习如何写中）
 */

 /*
 Secret agent Maria was sent to Algorithms City to carry out an especially dangerous mission. After
 several thrilling events we find her in the first station of Algorithms City Metro, examining the time
 table. The Algorithms City Metro consists of a single line with trains running both ways, so its time
 table is not complicated.
 Maria has an appointment with a local spy at the last station of Algorithms City Metro. Maria
 knows that a powerful organization is after her. She also knows that while waiting at a station, she is
 at great risk of being caught. To hide in a running train is much safer, so she decides to stay in running
 trains as much as possible, even if this means traveling backward and forward. Maria needs to know
 a schedule with minimal waiting time at the stations that gets her to the last station in time for her
 appointment. You must write a program that finds the total waiting time in a best schedule for Maria.
 The Algorithms City Metro system has N stations, consecutively numbered from 1 to N. Trains
 move in both directions: from the first station to the last station and from the last station back to the
 first station. The time required for a train to travel between two consecutive stations is fixed since all
 trains move at the same speed. Trains make a very short stop at each station, which you can ignore
 for simplicity. Since she is a very fast agent, Maria can always change trains at a station even if the
 trains involved stop in that station at the same time.

 Input
 The input file contains several test cases. Each test case consists of seven lines with information as
 follows.
 Line 1. The integer N (2 ≤ N ≤ 50), which is the number of stations.
 Line 2. The integer T (0 ≤ T ≤ 200), which is the time of the appointment.
 Line 3. N − 1 integers: t1, t2, . . . , tN−1 (1 ≤ ti ≤ 20), representing the travel times for the trains
 between two consecutive stations: t1 represents the travel time between the first two stations, t2
 the time between the second and the third station, and so on.
 Line 4. The integer M1 (1 ≤ M1 ≤ 50), representing the number of trains departing from the first
 station.
 Line 5. M1 integers: d1, d2, . . . , dM1 (0 ≤ di ≤ 250 and di < di+1), representing the times at which
 trains depart from the first station.
 Line 6. The integer M2 (1 ≤ M2 ≤ 50), representing the number of trains departing from the N-th
 station.
 Line 7. M2 integers: e1, e2, . . . , eM2 (0 ≤ ei ≤ 250 and ei < ei+1) representing the times at which
 trains depart from the N-th station.
 The last case is followed by a line containing a single zero.

 Output
 For each test case, print a line containing the case number (starting with 1) and an integer representing
 the total waiting time in the stations for a best schedule, or the word ‘impossible’ in case Maria is
 unable to make the appointment. Use the format of the sample output.

 Sample Input
 4
 55
 5 10 15
 4
 0 5 10 20
 4
 0 5 10 15
 4
 18
 1 2 3
 5
 0 3 6 10 12
 6
 0 3 5 7 12 15
 2
 30
 20
 1
 20
 7
 1 3 5 7 11 13 17
 0

 Sample Output
 Case Number 1: 5
 Case Number 2: 0
 Case Number 3: impossible

 */

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
#define minof(x, y) (((x) < (y)) ? (x) : (y))
#define maxof(x, y) (((y) < (x)) ? (x) : (y))

//const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
#define MAX 10000
// end of header

#define INF 10000
#define MAX_STATS 51
#define MAX_TRAINS 50
#define MAX_TIME 201

int main() {
    int numOfStats;
    int targetTime;
    int travelTime[MAX_STATS];
    int leftTrainCount;
    int leftStartTime[MAX_TRAINS];
    int rightTrainCount;
    int rightStartTime[MAX_TRAINS];

    int dp[MAX_TIME][MAX_STATS];
    bool hasTrain[MAX_TIME][MAX_STATS][2];

    int elapsedLeftTravelTime[MAX_STATS][MAX_TRAINS]; // 从左向右开
    int elapsedRightTravelTime[MAX_STATS][MAX_TRAINS]; // 从右向左开

    int cases = 0;

    while (scanf("%d", &numOfStats) == 1 && numOfStats != 0) {

        // read
        scanf("%d", &targetTime);
        erep(i, 1, numOfStats - 1) {
            scanf("%d", travelTime + i);
        }
        scanf("%d", &leftTrainCount);
        rep(i, 0, leftTrainCount) {
            scanf("%d", leftStartTime + i);
        }
        scanf("%d", &rightTrainCount);
        rep(i, 0, rightTrainCount) {
            scanf("%d", rightStartTime + i);
        }

        // init
        erep(j, 1, numOfStats - 1) {
            dp[targetTime][j] = INF;
        }
        dp[targetTime][numOfStats] = 0;
        memset(hasTrain, false, sizeof(hasTrain));

        // judge if [time][station] has trains with 2 auxiliary arrays
        rep(i, 0, leftTrainCount) {
            elapsedLeftTravelTime[1][i] = leftStartTime[i];
            erep(j, 2, numOfStats) {
                elapsedLeftTravelTime[j][i] = elapsedLeftTravelTime[j - 1][i] + travelTime[j - 1];
            }
        }
        rep(i, 0, rightTrainCount) {
            elapsedRightTravelTime[numOfStats][i] = rightStartTime[i];
            per(j, 1, numOfStats) {
                elapsedRightTravelTime[j][i] = elapsedRightTravelTime[j + 1][i] + travelTime[j];
            }
        }
        int time;
        erep(i, 1, numOfStats) {
            rep(j, 0, leftTrainCount) {
                time = elapsedLeftTravelTime[i][j];
                if (time <= targetTime) {
                    hasTrain[time][i][0] = true;
                }
            }
            rep(j, 0, rightTrainCount) {
                time = elapsedRightTravelTime[i][j];
                if (time <= targetTime) {
                    hasTrain[time][i][1] = true;
                }
            }
        }

        // dp
        per(i, 0, targetTime) {
            erep(j, 1, numOfStats) {
                // wait for 1 unit time
                dp[i][j] = dp[i + 1][j] + 1;
                // take a train heading for right
                if (j < numOfStats && hasTrain[i][j][0] && (i + travelTime[j] <= targetTime)) {
                    dp[i][j] = minof(dp[i][j], dp[i + travelTime[j]][j + 1]);
                }
                // take a train heading for left
                if (j > 1 && hasTrain[i][j][1] && (i + travelTime[j - 1] <= targetTime)) {
                    dp[i][j] = minof(dp[i][j], dp[i + travelTime[j - 1]][j - 1]);
                }
            }
        }

        // output
        printf("Case Number %d: ", ++cases);
        if (dp[0][1] > MAX_TIME) {
            printf("impossible\n");
        } else {
            printf("%d\n", dp[0][1]);
        }
    }
}
