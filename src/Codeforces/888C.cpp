/**
 * Created by LonelyEnvoy on 2017-11-16.
 * C. K-Dominant Character
 * Keywords: implementation
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)

#define MAX 100001
#define INF 0x3f3f3f3f

char buf[MAX];
int len;
int pos[256];
int dis[256];

int main() {
    scanf("%s", buf);
    len = strlen(buf);
    memset(pos, -1, sizeof(pos));
    rep(i,0,len) {
        char c = buf[i];
        dis[c] = max(dis[c], i - pos[c]);
        pos[c] = i;
    }

    erep(i,'a','z') if (dis[i]) dis[i] = max(dis[i], len-pos[i]);

    int heap = INF;
    erep(i,'a','z') {
        if (dis[i]) heap = min(heap, dis[i]);
    }
    if (heap == INF) return puts("1"), 0;
    printf("%d\n", min(heap, len/2+1));
}


