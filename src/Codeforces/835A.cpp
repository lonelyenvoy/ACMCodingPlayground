/**
 * Created by LonelyEnvoy on 2017-11-6.
 * A. Key races
 * Keywords: simple math
 */

#include <cstdio>

int main() {
    int s,v1,v2,t1,t2;
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    int ans = v1*s+t1*2 - (v2*s+t2*2);
    if (!ans) return puts("Friendship"), 0;
    puts(ans < 0 ? "First" : "Second");
}
