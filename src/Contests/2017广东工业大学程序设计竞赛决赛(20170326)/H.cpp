/**
 * Created by LonelyEnvoy on 2017-3-28.
 * Problem H: tmk买礼物
 * Keywords: implementation
 * Limits: high run-time efficiency required; 不能用暴力法生成子集
 */

 /*
 Description

 今天是校赛的日子，为了庆祝这么喜庆的日子，TMK打算买些礼物给女票LSH庆祝一下。
 TMK进入了雪梨超市，然后刚踏入的一瞬间，店主就对TMK说：“恭喜你成为了本店第2147483647位顾客，本店在搞一个活动，对本店第2147483647位顾客进行赠送活动。你先看看你有多少钱？”
 TMK一摸口袋，发现只有n个硬币，每个硬币的价值为a[i]。
 然后店主继续说：“现在你用你的钱凑一些数，如果你的钱能凑成[0,x]里面所有的数，那么你将会免费获得该店价值x元的代金券，假设你有四个硬币面值分别为1,2,4，100，你就可以凑成[0,7]里面所有的数，我们将会送你7元的代金券。现在就用你的硬币来试试吧。Enjoy yourself！”
 在TMK努力凑钱的时候，店主想知道他要送多少代金券给TMK。
 Input

 第一行一个整数T，表示数据组数。
 对于每组数据，首先读入一个整数n（n<=100000），然后接下来的一行有n个整数，表示a[i] （0<a[i]<=1e9）
 Output

 对于每个数据，输出一个整数x，表示店主要送x元的代金券给TMK
 Sample Input
 1
 3
 1 2 3
 Sample Output
 6
 */

 /*
 解题思路：
 1. 需要将n个硬币凑成某个数，首先想到暴力生成子集，然后逐个求和，并将求到的和放进visit布尔数组，最后遍历数组找到第一个false的位置即求到解。
    但这种方法造成的时间和空间损耗极大，会TLE。
 2. 更优的方法：先将硬币从小到大排序。设max为当前已凑到的（连续序列中的）最大值，观察可以发现对于第 i 个硬币，如果 a[i+1] > max+1，
    那就GG了，因为第 i+1 个硬币的加入已经超过了 max + 1，再也无法凑出刚好比 max 大 1 的数，所以截止，能凑到的最大数就是max。
    如果 a[i+1] <= max+1 的话就可以继续凑，max += a[i + 1]。
 需注意的地方：
 保存 max 需要用 long long 型，否则会溢出。
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
#define MAX 100000
// end of header

int coins[MAX];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        rep(i, 0, n) {
            scanf("%d", coins + i);
        }
        sort(coins, coins + n);

        ll max = 0;
        rep(i, 0, n) {
            if (coins[i] > max + 1) {
                break;
            }
            max += coins[i];
        }
        printf("%lld\n", max);
    }
}