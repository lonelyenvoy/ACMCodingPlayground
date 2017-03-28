/**
 * Created by LonelyEnvoy on 2017-3-28.
 * Mock Test Problem
 * Keywords: brute force，生成子集
 * Source: 蓝桥杯大赛辅导视频-百度传课-第三讲：经典的递归问题(2)
 * See: https://www.chuanke.com/?mod=school&act=show&do=course&sid=8197723
 */

/*
整数的分划问题。
如，对于正整数 n = 6，可以分划为：
6
5+1
4+2,4+1+1
3+3,3+2+1,3+1+1+1
2+2+2,2+2+1+1,2+1+1+1+1
1+1+1+1+1+1
现在的问题是，对于给定的正整数n，编写算法打印所有划分。
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

struct Node {
    int a[MAX];
};

int lastBeginning = -1;
bool first = true;

void permutation(Node node, int n, int k) {
    if (n == 0) {
        if (lastBeginning == node.a[0]) {
            printf(",");
        } else if (!first) {
            printf("\n");
        }
        first = false;
        rep(i, 0, k) {
            if (i == 0) {
                lastBeginning = node.a[0];
            } else {
                printf("+");
            }
            printf("%d", node.a[i]);
        }
    }

    per(i, 1, n + 1) {
        if (k > 0 && node.a[k - 1] < i) continue;
        node.a[k] = i;
        permutation(node, n - i, k + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node node;
    permutation(node, n, 0);
}
