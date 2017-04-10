/**
 * Created by LonelyEnvoy on 2017-4-10.
 * A. Kefa and First Steps
 * Keywords: 贪心，水题
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

#define MAX 100001

int data[MAX];

int main() {
    int n;
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", data + i);
    }
    int count = 1;
    int maxCount = 1;
    rep(i,1,n) {
        if(data[i] >= data[i-1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 1;
        }
    }
    printf("%d\n", maxCount);
}
