/**
 * Created by LonelyEnvoy on 2017-6-18.
 * Girls and Boys
 * Keywords: 二分匹配，匈牙利算法
 */

// 参考资料：http://blog.csdn.net/acm_davidcn/article/details/5862076

#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 505  
  
int n;  
int graph[MAX][MAX];  
int visited[MAX];  
int match[MAX];  
  
int hungary(int u){  
    rep(i,0,n) {
        if(!visited[i] && graph[u][i]){  
            visited[i] = 1;  
            if(match[i] == -1 || hungary(match[i])){  
                match[i] = u;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
int main(){  
    while(cin>>n){  
        memset(graph, 0, sizeof(graph));  
        memset(match, -1, sizeof(match));  
        rep(i,0,n) {
            int stu, knowN, tmp_know;  
            scanf("%d: (%d)", &stu, &knowN);  
            rep(j,0,knowN) {
                cin>>tmp_know;  
                graph[i][tmp_know] = 1;  
            }  
        }  
        int ans = 0;  
        rep(i,0,n) {
            memset(visited, 0, sizeof(visited));  
            if(hungary(i))  
                ans++;  
        }  
        cout<<n - ans / 2<<endl;
    }  
    return 0;  
}  


