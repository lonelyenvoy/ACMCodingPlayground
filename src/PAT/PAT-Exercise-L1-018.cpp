/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L1-018. 大笨钟
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
	int hh;
	int mm;
	scanf("%d:%d", &hh, &mm);
	if (hh >= 0 && hh <= 11 || (hh == 12 && mm == 0)) {
		printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
		return 0;
	}
	if (hh > 12) hh -= 12;
	if (mm > 0) hh++;
	for (int i = 0; i < hh; i++) {
		printf("Dang");
	}
	printf("\n");
}