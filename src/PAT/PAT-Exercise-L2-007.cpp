/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L2-007. 家庭房产
 * Keywords: 并查集
 *
 * 本题情况略微复杂，用搜索（dfs）比用并查集更容易解决问题
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <limits>
using namespace std;

#define MAX 10000

struct Node {
    int id;
    int count;
    float avgHouses;
    float avgAreas;
};

vector<Node> ans;
vector<int> persons[MAX];
int houses[MAX];
int areas[MAX];
bool visited[MAX];
bool validPerson[MAX]; // determines whether persons[i] is valid
int personCount;
int minId;
int thisSumHouses;
int thisSumAreas;
const int INF = numeric_limits<int>::max();

inline void init() {

}

inline int min(int a, int b) {
    return a < b ? a : b;
}

bool cmp(const Node& n1, const Node& n2) {
    if (n1.avgAreas != n2.avgAreas) return n1.avgAreas > n2.avgAreas;
    return n1.id < n2.id;
}

void dfs(int id) {
    visited[id] = true;
    minId = min(minId, id);
    thisSumHouses += houses[id];
    thisSumAreas += areas[id];
    personCount++;

    for (int i = 0, size = persons[id].size(); i < size; i++) {
        if (!visited[persons[id][i]]) {
            dfs(persons[id][i]);
        }
    }
}

int main() {

    init();

    int id;
    int parents[2];
    int kidCount;
    int kids[5];

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &id, &parents[0], &parents[1], &kidCount);
        for (int i = 0; i < kidCount; i++) {
            scanf("%d", &kids[i]);
        }
        scanf("%d%d", &houses[id], &areas[id]);

        // push parents
        for (int i = 0; i < 2; i++) {
            if (parents[i] != -1) {
                persons[id].push_back(parents[i]);
                persons[parents[i]].push_back(id);
            }
        }

        // push kids
        for (int i = 0; i < kidCount; i++) {
            persons[id].push_back(kids[i]);
            persons[kids[i]].push_back(id);
        }

        // set valid
        validPerson[id] = true;
    }

    Node node;
    int setCount = 0;
    for (int i = 0; i < MAX; i++) {
        if (validPerson[i] && !visited[i]) {
            setCount++;
            thisSumHouses = thisSumAreas = 0;
            minId = INF;
            personCount = 0;
            dfs(i);
            node.id = minId;
            node.count = personCount;
            node.avgHouses = (float)thisSumHouses / personCount;
            node.avgAreas = (float)thisSumAreas / personCount;
            ans.push_back(node);
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", setCount);
    for (int i = 0, size = ans.size(); i < size; i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].count, ans[i].avgHouses, ans[i].avgAreas);
    }
}
