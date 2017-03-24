/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L1-031. 到底是不是太胖了
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
	int N;
	scanf("%d", &N);
	float H;
	float W;
	float stdW;
	while (N--) {
		scanf("%f%f", &H, &W);
		W /= 2;
		stdW = (H - 100) * 0.9;
		if ((float)abs(W - stdW) < (float)(stdW * 0.1)) {
			printf("You are wan mei!\n");
		} else if (W > stdW) {
			printf("You are tai pang le!\n");
		} else {
			printf("You are tai shou le!\n");
		}
	}
}
