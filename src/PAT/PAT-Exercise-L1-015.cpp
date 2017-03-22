/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-007. 跟奥巴马一起画方块
 * Keywords: 水题
 */

#include <cstdio>
using namespace std;

int round(float n) {
	return (int)(n + 0.5);
}

int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);
	for (int i = 0; i < round((float)n / 2); i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", c);
		}
		printf("\n");
	}
}
