/**
 * Created by LonelyEnvoy on 2017-3-21.
 * L3-003. 社交集群
 * Keywords: 并查集
 */

 /* ---------- 此代码存在BUG，只能通过部分测试样例 ---------- */

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

int main() {
	freopen("c:\\in.txt", "r", stdin);

	vector< set<int> > sets;
	int personCounts[MAX];
	int numOfSets = 0;
	memset(personCounts, 0, sizeof(int) * MAX);

	int persons;
	int hobbyCount;
	int hobbies[MAX];
//	int existedSetNum;
	int unionSetNum[2];
	int unionSetNumCurr;
	scanf("%d", &persons);
	while (persons--) {
		memset(unionSetNum, -1, sizeof(int) * 2);
		unionSetNumCurr = 0;
		scanf("%d:", &hobbyCount);
		for (int i = 0; i < hobbyCount; i++) {
			scanf("%d", hobbies + i);
		}
//		existedSetNum = -1;
		for (int i = 0; i < sets.size(); i++) {
			for (int j = 0; j < hobbyCount; j++) {
				if (sets[i].count( hobbies[j] ) != 0) { // found existed hobby
//					existedSetNum = i;
					unionSetNum[unionSetNumCurr++] = i;
					if (unionSetNumCurr == 2) {
						break;
					}
				}
			}
		}
		if (unionSetNumCurr != 0) { // parse existed hobby
//			personCounts[existedSetNum]++;
			personCounts[unionSetNum[0]]++;
			// judge if two set should be unioned
			if (unionSetNumCurr == 2 && (unionSetNum[0] != unionSetNum[1])) { // union
				vector<int> v(sets[unionSetNum[0]].size() + sets[unionSetNum[1]].size());
				set_union(sets[unionSetNum[0]].begin(), sets[unionSetNum[0]].end(),
						sets[unionSetNum[1]].begin(), sets[unionSetNum[1]].end(),
						v.begin());
				sets.erase(sets.begin() + unionSetNum[0]);
				sets.erase(sets.begin() + unionSetNum[1]);
				set<int> newSet;
//				copy(v.begin(), v.end(), newSet.begin());
				for (int i = 0; i < v.size(); i++) {
					newSet.insert(v[i]);
				}
				sets.insert(sets.begin() + unionSetNum[0], newSet);
				numOfSets--;
				personCounts[unionSetNum[0]] += personCounts[unionSetNum[1]];
				// reset personCounts position
				for (int i = unionSetNum[1]; i < sets.size(); i++) {
					personCounts[i] = personCounts[i + 1];
				}
			} else {
				for (int i = 0; i < hobbyCount; i++) { // insert all new hobbies
//					sets[existedSetNum].insert(hobbies[i]);
					sets[unionSetNum[0]].insert(hobbies[i]);
				}
			}
		} else { // parse new hobby
			numOfSets++;
			personCounts[numOfSets - 1] = 1;
			set<int> newSet;
			for (int i = 0; i < hobbyCount; i++) { // insert all new hobbies
				newSet.insert(hobbies[i]);
			}
			sets.push_back(newSet);
		}
	}
	printf("%d\n", numOfSets);
	sort(personCounts, personCounts + numOfSets, greater<int>());
	for (int i = 0; i < numOfSets; i++) {
		printf("%d", personCounts[i]);
		if (i != numOfSets - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

