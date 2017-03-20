/**
 * Created by LonelyEnvoy on 2017-3-21.
 * L1-020. 帅到没朋友
 * Keywords: STL Set的简单应用
 */

#include <cstdio>
#include <set>
using namespace std;

int main() {
    set<int> people;
    set<int> queried;

    int T;
    int numberOfPeople;
    int id;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &numberOfPeople);
        if (numberOfPeople < 2) { // ignore those 朋友圈 which has only one person
            scanf("%d", &id);
            continue;
        }
        while (numberOfPeople--) {
            scanf("%d", &id);
            people.insert(id);
        }
    }
    bool hasHandsome = false;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &id);
        if (people.find(id) == people.end() && queried.find(id) == queried.end()) { // he has no friend and not queried
            if (hasHandsome) {
                printf(" ");
            }
            queried.insert(id); // log queried
            hasHandsome = true;
            printf("%05d", id);
        }
    }
    if (!hasHandsome) {
        printf("No one is handsome\n");
    } else {
        printf("\n");
    }
}