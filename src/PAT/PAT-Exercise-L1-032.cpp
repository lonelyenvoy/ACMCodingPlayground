/**
 * Created by LonelyEnvoy on 2017-3-24.
 * L1-032. Left-pad
 * Keywords: 水题，简单字符串处理
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

#define MAX 100000

int main() {
	int targetLen;
	char replaceChar;
	scanf("%d %c", &targetLen, &replaceChar);
	char cstr[MAX];
	getchar(); // eat '\n'
	scanf("%[^\n]", cstr);
	string str(cstr);
	int len = str.length();

	if (targetLen == len) {
		printf("%s\n", cstr);
	} else if (targetLen < len) {
		string newStr = str.substr(len - targetLen);
		printf("%s\n", newStr.c_str());
	} else {
		char newcStr[MAX];
		for (int i = 0; i < targetLen - len; i++) {
			newcStr[i] = replaceChar;
		}
		strcat(newcStr, cstr);
		printf("%s\n", newcStr);
	}
}
