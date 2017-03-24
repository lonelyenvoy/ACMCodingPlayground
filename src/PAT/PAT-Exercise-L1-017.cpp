/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L1-017. 到底有多二
 * Keywords: 水题
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	char c;
	char buffer;
	int countTwo = 0;
	bool isNeg = false;
	bool isEven = false;
	int length = 0;
	while (scanf("%c", &c) == 1) {
		if (c == '\n' || c == '\r') {
			break;
		}
		buffer = c;
		if (c == '-') {
			isNeg = true;
			continue;
		}
		length++;
		if (c == '2') {
			countTwo++;
		}
	}
	if (buffer % 2 == 0) {
		isEven = true;
	}
	float ans = (float)countTwo / length;
	if (isNeg) {
		ans *= 1.5;
	}
	if (isEven) {
		ans *= 2;
	}
	printf("%.2f\%\n", ans * 100);
}