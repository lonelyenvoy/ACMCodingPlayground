/**
 * Created by LonelyEnvoy on 2017-4-12.
 * C. Given Length and Sum of Digits...
 * Keywords: greedy, implementation
 * Limits: High run-time efficiency required，不能用暴力法
 */

// 题意：找出最小和最大的m位数，其各位数字之和为s（1<=m<=100, 0<=s<=900）

// 解题思路：用一个数组a模拟，下标0放个位，1放十位，以此类推。先从高位开始放，每次从s中取得不大于9的数，
// 从下标第m-1位放到第0位，过程中s不断更新，直到s为0停止。如果放完了以后s>0，则说明无论怎么放都用不完s，
// 无解。否则[m-1, 0]即为所求的最大数。
// 求最小数的方法：从[0, m-1]找。对数组a从左向右扫描，找到第一个非零元素k，a[0]++，a[k]--
// （即将a[k]借一位放到a[0]上），这样能保证a[0]==1，找到最小数。

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
typedef long long ll;

#define MAX 101

int d[MAX];

int main() {
    int m, s;
    scanf("%d%d", &m, &s);
    if (s == 0) {
        if (m == 1) {
            printf("0 0\n");
        } else {
            printf("-1 -1\n");
        }
        return 0;
    }
    rep(i,0,m) {
        d[m-1-i] = min(s, 9);
        s -= min(s, 9);
    }
    if (s > 0) {
        printf("-1 -1\n");
        return 0;
    }
    int k;
    for (k = 0; d[k] == 0; k++);
    d[0]++;
    d[k]--;
    rep(i,0,m) {
        printf("%d", d[i]);
    }
    printf(" ");
    d[0]--;
    d[k]++;
    per(i,0,m) {
        printf("%d", d[i]);
    }
    printf("\n");
}
