/**
 * Created by LonelyEnvoy on 2017-4-9.
 * Fibonacci
 * Keywords: 暴力，水题
 */

/*
Problem F. Fibonacci
我们知道Fibonacci数组通项函数定义如下：
F(1) = 1，F(2) = 2  F(N) = F(N-1) + F(N-2), N > 2
F(S) = F(A1) + F(A2) + ... + F(Am)

Input
第一行输入一个整数T，表示有T组测试数据。对于每一组测试数据，第一行是一个正整数M，第二行是M个正整数A1, A2, ..., Am。
0 < M < 10000
0 < Ai < 1000000

Output
输出有T行，每一行对应一组测试数据。对于每组测试数据，如果能找到满足的S，则输出S，否则输出-1.

Sample input and output
2
2
4 5
3
4 5 6

6
-1
*/

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
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

#define rep(i,a,n) for (int i = a; i < n; i++)
#define erep(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n-1; i >= a; i--)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 100

int fibo[MAX];

void init() {
    fibo[1] = 1;
    fibo[2] = 2;
}
int dabiao(int i) {
    if (fibo[i] > 0) return fibo[i];
    return fibo[i] = dabiao(i-1) + dabiao(i-2);
}

int main() {
    init();
    dabiao(30);

    int T;
    int m;
    int num;
    int sum = 0;
    bool found;
    scanf("%d", &T);
    while (T--) {
        found = false;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &num);
            sum += fibo[num];
        }
        for (int i = 0; i <= 30; i++) {
            if (sum == fibo[i]) {
                found = true;
                printf("%d\n", i);
                break;
            }
        }
        if (!found) {
            printf("-1\n");
        }
    }
}
