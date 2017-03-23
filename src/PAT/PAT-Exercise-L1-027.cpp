/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-027. 出租
 * Keywords: 水题
 */


#include <cstdio>
#include <vector>
#include <set>
using namespace std;

set<int, greater<int> > s;
vector<int> arr;
int index[11];

int main() {
	char num[12];
	for (int i = 0; i < 11; i++) {
		scanf("%c", num + i);
		s.insert(num[i] - '0');
	}
	while (!s.empty()) {
		int k = *s.begin();
		s.erase(k);
		arr.push_back(k);
	}
	for (int i = 0; i < 11; i++) {
		int curr = num[i] - '0';
		int pos;
		for (pos = 0; pos < arr.size(); pos++) {
			if (arr[pos] == curr) {
				break;
			}
		}
		index[i] = pos;
	}
	printf("int[] arr = new int[]{");
	bool first = true;
	for (int i = 0; i < arr.size(); i++) {
		if (!first) {
			printf(",");
		} else {
			first = false;
		}
		printf("%d", arr[i]);
	}
	printf("};\n");
	printf("int[] index = new int[]{");
	first = true;
	for (int i = 0; i < 11; i++) {
		if (!first) {
			printf(",");
		} else {
			first = false;
		}
		printf("%d", index[i]);
	}
	printf("};\n");
}
