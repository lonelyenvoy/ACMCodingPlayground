/**
 * Created by LonelyEnvoy on 2017-4-4.
 * Another Crisis
 * Keywords: dp
 */

// 状态定义：让第 u 个 employee 给上级发信至少需要 d(u) 个下层的 workers / employees 向 u 发信
// 状态转移方程： d(u) = sum{ children[u][i] }, i ∈[0, numberOfPeopleNeeded]
//              numberOfPeopleNeeded = ceil( numberOfChildren(u) * T / 100 )
// 只需计算出 u 的所有子节点的 d(u)，然后将其升序排列，取得前 numberOfPeopleNeeded 个值的和。
// 由于本题是树状结构，子问题不会被重复计算，无需记忆化处理。

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <limits>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; ++i)
#define erep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, a, n) for (int i = n - 1; i >= a; --i)

const int INF = 0x3f3f3f3f;
const double EPS = numeric_limits<double>::epsilon();
typedef long long ll;
// end of header

#define MAX 100001

vector<int> childs[MAX];
int n;
int t;

int minWorker(int u) {
    int size = childs[u].size();
    if (size == 0) {
        return 1;
    }

    vector<int> workers; // 如需要创建不确定大小的数组，应使用vector代替，提高效率，减少代码量
    rep(i, 0, size) {
        workers.push_back(minWorker(childs[u][i]));
    }
    sort(workers.begin(), workers.end());
    int needed = ceil((double)size * t / 100);
    int sum = 0;
    rep(i, 0, needed) {
        sum += workers[i];
    }
    return sum;
}

int main() {
    while (~scanf("%d%d", &n, &t) && n && t) {

        rep(i, 0, MAX) { // 注意：必须全部清空，不能只清除到n！
            childs[i].clear();
        }

        int parent;
        erep(i, 1, n) {
            scanf("%d", &parent);
            childs[parent].push_back(i);
        }

        printf("%d\n", minWorker(0));
    }
}
