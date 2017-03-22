/**
 * Created by LonelyEnvoy on 2017-3-21.
 * L1-030. 一帮一
 * Keywords: 水题
 */

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct Student {
	int sex;
	char name[9];
	bool paired;
};

int main() {
	freopen("C:\\in.txt", "r", stdin);

	vector<Student> v;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Student stu;
		stu.paired = false;
		scanf("%d%s", &stu.sex, stu.name);
		v.push_back(stu);
	}

	for (int count = 0; count < n; count++) {
		int i = count;
		int j = n - 1;
		Student s1 = v[i];
		Student s2 = v[j];

		while (s1.sex == s2.sex || s2.paired) {
			s2 = v[--j];
			if (j < 1) {
				goto end;
			}
		}
		printf("%s %s\n", s1.name, s2.name);
		v[i].paired = v[j].paired = true;
	}
	end:
		return 0;

}