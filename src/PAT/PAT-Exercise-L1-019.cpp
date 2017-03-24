/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L1-019. 谁先倒
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
	int jiaJiu;
	int yiJiu;
	int N;
	scanf("%d%d%d", &jiaJiu, &yiJiu, &N);
	jiaJiu++;
	yiJiu++;
	int jiaHan;
	int jiaHua;
	int yiHan;
	int yiHua;
	int winner; // 0 jia, 1 yi
	int jiaHe = 0;
	int yiHe = 0;
	while(N--) {
		scanf("%d%d%d%d", &jiaHan, &jiaHua, &yiHan, &yiHua);
		if (jiaHua == jiaHan + yiHan && yiHua != jiaHan + yiHan) {
			if (++jiaHe == jiaJiu) {
				winner = 0;
			}
		}
		if (jiaHua != jiaHan + yiHan && yiHua == jiaHan + yiHan) {
			if (++yiHe == yiJiu) {
				winner = 1;
			}
		}
		if (jiaHe == jiaJiu || yiHe == yiJiu) {
			if (winner == 0) {
				printf("A\n%d\n", yiHe);
			} else {
				printf("B\n%d\n", jiaHe);
			}
			break;
		}
	}
}
