/**
 * Created by LonelyEnvoy on 2017-4-10.
 * A. Puzzles
 * Keywords: 简单排序，水题
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

#define MAX 51

int data[MAX];

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    rep(i,0,m) {
        scanf("%d", data + i);
    }
    sort(data, data+m);
    int diff;
    int minDiff = INF;
    erep(i,n-1,m-1) {
        diff = data[i]-data[i-n+1];
        if (diff < minDiff) minDiff = diff;
    }
    printf("%d\n", minDiff);
}
