/**
 * Created by LonelyEnvoy on 2017-11-6.
 * A. Text Volume
 * Keywords: simple strings, implementation
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 201

int n;
char str[MAX];
int heap;

int main() {
    scanf("%d", &n);
    getchar();
    fgets(str, MAX, stdin);
    int count = 0;
    rep(i,0,n) {
        char& c = str[i];
        if (c == ' ') { heap = max(heap, count); count = 0; }
        else if (c >= 'A' && c <= 'Z') ++count;
    }
    printf("%d\n", max(heap, count));
}

