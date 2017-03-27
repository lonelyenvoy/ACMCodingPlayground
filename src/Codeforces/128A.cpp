/**
 * Created by LonelyEnvoy on 2017-3-27.
 * A. Statues
 * Keywords: dfs
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
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

#define rep(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;

const int INF = numeric_limits<int>::max();
const double EPS = numeric_limits<double>::epsilon();
#define MAX 100001



char maze[8][8];
const int posDelta[2][9] = {
        -1, -1, 0, 1, 1, 1, 0, -1, 0,
        0, 1, 1, 1, 0, -1, -1, -1, 0
};
bool foundSolution = false;
bool first = true;
int steps = 0;

void dfs(int x, int y) {
    if (!first) {
        per(i, 0, 8) {
            rep(j, 0, 8) {
                if (maze[i][j] == 'S') {
                    if (i == 7) {
                        maze[i][j] = '.';
                        continue;
                    }
                    if (maze[i + 1][j] == 'M') { // hit Maria
                        return;
                    }
                    maze[i][j] = '.';
                    maze[i + 1][j] = 'S';
                }
            }
        }
    } else {
        first = false;
    }

    char mazeCache[8][8];
    int newx, newy;
    rep(i, 0, 9) {
        newx = x + posDelta[0][i];
        newy = y + posDelta[1][i];
        if (newx >= 0 && newx <= 7 && newy >= 0 && newy <= 7 && maze[newx][newy] != 'S' && !foundSolution) {
            if (maze[newx][newy] == 'A') {
                foundSolution = true;
                return;
            }
            memcpy(mazeCache, maze, sizeof(maze));
            maze[x][y] = '.';
            maze[newx][newy] = 'M';
            steps++;
            dfs(newx, newy);
            steps--;
            memcpy(maze, mazeCache, sizeof(mazeCache));
        }
    }

}

int main() {
    bool hasStatue = false;
    char c;
    rep(i, 0, 8) {
        rep(j, 0, 8) {
            scanf("%c", &c);
            if (c == '\n' || c == '\n') {
                j--;
                continue;
            }
            if (c == 'S') {
                hasStatue = true;
            }
            maze[i][j] = c;
        }
    }
    if (!hasStatue) {
        printf("WIN\n");
        return 0;
    }
    dfs(7, 0);
    if (foundSolution) {
        printf("WIN\n");
    } else {
        printf("LOSE\n");
    }
    return 0;
}
