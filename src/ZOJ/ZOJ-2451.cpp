/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Minimizing maximizer
 * Keywords: dp，线段树
 */

#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

const int MAXN = 50005;  
const int MAXM = 500005;  
const int INF = 0x2f7f7f7f;  
  
int a[MAXN<<2];  
  
void build(int l, int r, int rt) {  
    a[rt] = INF;  
    if (l == r) return ;  
    int m = (l + r) >> 1;  
    build(l, m, rt<<1);  
    build(m+1, r, rt<<1|1);  
}  
void update(int R, int val, int l, int r, int rt) {  
    if (a[rt] > val) a[rt] = val;  
    if (l != r) {  
        int m = (l + r) >> 1;  
        if (R <= m) update(R, val, l, m, rt<<1);  
        else update(R, val, m+1, r, rt<<1|1);  
    }  
}  
int query(int L, int R, int l, int r, int rt) {  
    if (L <= l && r <= R)  
        return a[rt];  
    int m = (l + r) >> 1;  
    if (R <= m) return query(L, R, l, m, rt<<1);  
    else if (L > m) return query(L, R, m+1, r, rt<<1|1);  
    else {  
        int ret1 = query(L, R, l, m, rt<<1);  
        int ret2 = query(L, R, m+1, r, rt<<1|1);  
        return (ret1 > ret2) ? ret2 : ret1;  
    }  
}  
  
int main() {  
    int n, m, a, b;  
    while (scanf("%d %d", &n, &m) == 2) {  
        build(1, n, 1);  
        update(1, 0, 1, n, 1);  
        rep(i,0,m) {
            scanf("%d %d", &a, &b);  
            if (a < b) {  
                int x = query(a, b-1, 1, n, 1);  
                update(b, x+1, 1, n, 1);  
            }  
        }  
        printf("%d\n", query(n, n, 1, n, 1));    
    }  
    return 0;  
}  

