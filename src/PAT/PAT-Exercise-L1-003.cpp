/**
 * Created by LonelyEnvoy on 2017-3-21.
 * L1-003. 个位数统计
 * Keywords: 水题
 */

#include <cstdio>
using namespace std;

int main() {
	int count[10] = {0};
	char c;
	while ((c = getchar()) != '\n') {
		count[c - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0) {
			printf("%d:%d\n", i, count[i]);
		}
	}
}
