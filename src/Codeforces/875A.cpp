/**
 * Created by LonelyEnvoy on 2017-10-20.
 * A. Classroom Watch
 * Keywords: brute force
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

int n;
vector<int> v;

int digits(int a) {
    int count = 0;
    while (a) ++count, a/=10;
    return count;
}

bool check(int a) {
    int sum = 0;
    int b = a;
    while (a) sum+=a%10, a/=10;
    return b + sum == n;
}

int main() {
    scanf("%d", &n);
    rep(i,n-digits(n)*9,n) if (check(i)) v.push_back(i);
    printf("%d\n", v.size());
    bool first = true;
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
        if (!first) printf(" ");
        else first = false;
        printf("%d", *itr);
    }
    puts("");
}

