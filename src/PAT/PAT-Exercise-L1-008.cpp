/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-008. 求整数段和
 * Keywords: 水题
 */

#include <cstdio>
using namespace std;

int main() {
	int a;
	int b;
	scanf("%d%d", &a, &b);

	int sum = 0;
	int count = 0;
	while (a != b + 1) {
		count++;
		printf("% 5d", a);
		if (count % 5 == 0 && count != 0) {
			printf("\n");
		}
		sum += a;
		a++;
	}
	if (count % 5 != 0) {
		printf("\n");
	}
	printf("Sum = %d", sum);
}