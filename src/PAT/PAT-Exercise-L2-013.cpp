/**
 * Created by LonelyEnvoy on 2017-3-18.
 * L2-013. 红色警报
 * Keywords: dfs，floodfill，图的遍历
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 500

bool graph[MAX][MAX];
int n;

bool isNodeRemoved[MAX];
int indexOfNode[MAX];
void floodFill(int u, int id) {
    if (indexOfNode[u] != 0) { // already visited
        return;
    }
    // mark index
    indexOfNode[u] = id;

    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !isNodeRemoved[v]) {
            floodFill(v, id);
        }
    }
}

int numberOfConnectedBlock() {
    memset(indexOfNode, 0, sizeof(int) * MAX);
    int id = 0;
    for (int u = 0; u < n; u++) {
        if (indexOfNode[u] == 0 && !isNodeRemoved[u]) { // only visit the unvisited items
            floodFill(u, ++id);
        }
    }
    return id;
}

int main() {

    // init
    memset(graph, false, sizeof(bool) * MAX * MAX);
    memset(isNodeRemoved, false, sizeof(bool) * MAX);

    // read and parse
    int roadAmount;
    scanf("%d%d", &n, &roadAmount);
    int cityA;
    int cityB;
    for (int i = 0; i < roadAmount; i++) {
        scanf("%d%d", &cityA, &cityB);
        // create roads
        graph[cityA][cityB] = graph[cityB][cityA] = true;
    }
    int warAmount;
    scanf("%d", &warAmount);
    int lostCity;
    for (int i = 0; i < warAmount; i++) {

        // get number of connected block before war
        int originalParts = numberOfConnectedBlock();

        // read and remove city
        scanf("%d", &lostCity);
        isNodeRemoved[lostCity] = true;

        // judge if the country is split into more blocks than before
        if (originalParts >= numberOfConnectedBlock()) {
            // all cities are still connected, or the war involves only one city and no road
            printf("City %d is lost.\n", lostCity);
        } else {
            // the country is now split into more blocks
            printf("Red Alert: City %d is lost!\n", lostCity);
        }
        if (i == n - 1) { // lost the last city, game over
            printf("Game Over.\n");
        }
    }
}