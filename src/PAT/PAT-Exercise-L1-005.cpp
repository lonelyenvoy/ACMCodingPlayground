/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-007. 考试座位号
 * Keywords: 水题，map的简单应用
 */

#include <cstdio>
#include <map>
using namespace std;

struct Num {
	long long candidate;
	int seat;
};

int main() {
	map<int, Num> m;

	int T;
	scanf("%d", &T);
	while (T--) {
		Num num;
		int trySeat;
		scanf("%lld%d%d", &num.candidate, &trySeat, &num.seat);
		m.insert(pair<int, Num>(trySeat, num));
	}
	scanf("%d", &T);
	while (T--) {
		int trySeat;
		scanf("%d", &trySeat);
		printf("%lld %d\n", m[trySeat].candidate, m[trySeat].seat);
	}
}