/**
 * Created by LonelyEnvoy on 2017-11-6.
 * A. The Useless Toy
 * Keywords: implementation
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

//char model[] = {118, 60, 94, 62};

char s,e;
int r;

char ror(char c) {
    switch (c) {
        case 118: return 60;
        case 60: return 94;
        case 94: return 62;
        case 62: return 118;
    }
}

char rol(char c) {
    switch (c) {
        case 118: return 62;
        case 60: return 118;
        case 94: return 60;
        case 62: return 94;
    }
}

int main() {
    scanf("%c %c%d", &s, &e, &r);
    r %= 4;
    char left, right;
    left = right = s;
    rep(i,0,r) left = rol(left);
    rep(i,0,r) right = ror(right);
    if (e == left && e == right) puts("undefined");
    else if (e == left) puts("ccw");
    else if (e == right) puts("cw");
    else puts("undefined");
}

