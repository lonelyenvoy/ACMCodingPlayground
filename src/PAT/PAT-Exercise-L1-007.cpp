/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-007. 念数字
 * Keywords: 水题
 */

#include <cstdio>
using namespace std;

int main() {
	char py[][5] = {
		"ling",
		"yi",
		"er",
		"san",
		"si",
		"wu",
		"liu",
		"qi",
		"ba",
		"jiu"
	};

	bool first = true;
	char c;
	while (scanf("%c", &c) && c != '\n') {
		if (!first) {
			printf(" ");
		}
		first = false;
		if (c == '-') {
			printf("fu");
		} else {
			printf("%s", py[c - '0']);
		}
	}
	printf("\n");
}