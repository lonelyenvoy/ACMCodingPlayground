/**
 * Created by LonelyEnvoy on 2017-4-13.
 * Double Queue
 * Keywords: STL map的简单应用，水题（可自己写Splay Tree实现）
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

map<int, int> m;

int main() {
    int op;
    int k;
    int p;
    map<int,int>::iterator itr;
    while (~scanf("%d", &op) && op) {
        if (op == 1) {
            scanf("%d%d", &k, &p);
            m.insert(make_pair<int, int>(p, k));
        } else {
            if (m.empty()) printf("0\n");
            else if (op == 3) { // low
                itr = m.begin();
                printf("%d\n", itr->second);
                m.erase(itr);
            } else { // high
                itr = m.end();
                --itr;
                printf("%d\n", itr->second);
                m.erase(itr);
            }
        }
    }
}
