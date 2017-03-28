/**
 * Created by LonelyEnvoy on 2017-3-28.
 * Problem E: 倒水(Water)
 * Keywords: math，位运算
 */

 /*
 Description

 一天，CC买了N个容量可以认为是无限大的瓶子，开始时每个瓶子里有1升水。接着~~CC发现瓶子实在太多了，于是他决定保留不超过K个瓶子。每次他选择两个当前含水量相同的瓶子，把一个瓶子的水全部倒进另一个里，然后把空瓶丢弃。(不能丢弃有水的瓶子)
 显然在某些情况下CC无法达到目标，比如N=3,K=1。此时CC会重新买一些新的瓶子(新瓶子容量无限，开始时有1升水)，以到达目标。
 现在CC想知道，最少需要买多少新瓶子才能达到目标呢？
 Input

 第一行一个整数T，表示有T组数据。
 接着T行，每行两个正整数， N,K(1<=N<=10^9，K<=1000)。
 Output

 一个非负整数，表示最少需要买多少新瓶子。
 Sample Input
 3
 3 1
 13 2
 1000000 5
 Sample Output
 1
 3
 15808
 */

 /*
 解题思路：
 1. 列出 N ∈ [1， 32] 时，N 与所能聚合成的最小瓶子数量的映射的状态列表。
 2. 经观察可发现瓶子初始数量 N 的二进制表示中 1 的个数与所能聚合成的最小瓶子数量相等。
 3. 如果需要使最终瓶子数量减少，则需要增加瓶子数量，最多增加到 ceil( log(N) / log(2) ) 个瓶子一定能满足要求（达到2的下一个整数幂，瓶子数变为1个）。
 4. 如果从 N 个瓶子开始逐次 +1 再转二进制，计算二进制表示中 1 的个数是否 <= k，这样做效率太低，会TLE。
 5. 考虑到使用位运算 n & (n - 1) 将 n 的二进制表示中最低位的 1 替换为 0， 循环直到 n 中所有 1 均变成 0，可以统计出 1 的个数。（依然TLE）
 6. 为了减少从 N 开始寻找解的步进次数，继续观察状态表，发现大量的步进是在做无用功，因为瓶子数不减反增。
 7. 仅需找出 N 的二进制表示中最低位 1 的位置，步进 2^i，则瓶子数一定不会增加。（比如 10100 + 00100 = 11000）
 8. 按照 2^i 的步进数，可以确保最终一定抵达某个数为 2 的幂。
 9. “找出 N 的二进制表示中最低位 1 的位置” 可以使用 n & -n，此运算会保留二进制表示法中最低位的 1，其他 1 均变为 0。（比如 01010 & 10110 = 00010）
 10. AC
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
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
typedef long long ll;

const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
#define MAX 10000
// end of header


int numOf1(int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}

int main() {
    int T;
    int n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);

        int steps = 0;
        int currStep;
        while (numOf1(n) > k) {
            currStep = n & -n;
            n += currStep;
            steps += currStep;
        }
        printf("%d\n", steps);
    }
}
