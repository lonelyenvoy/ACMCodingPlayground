/**
 * Created by LonelyEnvoy on 2017-7-26.
 * B. Ilya and Queries
 * Keywords: segment tree
 */

#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define erep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i++)

#define MAX 100005

int tree[4 * MAX];
int n;
char str[MAX];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = str[left] == str[left+1] ? 1 : 0;
        return;
    }

    int mid = (left + right) >> 1;
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int begin, int end, int left, int right) {
    int mid = (begin + end) / 2;
    int leftValue = 0;
    int rightValue = 0;

    if (left > end || right < begin) {
        return 0;
    }

    if (left <= begin && right >= end) {
        return tree[node];
    }

    leftValue = query(2*node, begin, mid, left, right);
    rightValue = query(2*node+1, mid+1, end, left, right);

    return leftValue + rightValue;
}

// for debug
void print(int node, int left, int right) {
    if (left == right) {
        printf("%d ", tree[node]);
        return;
    }
    int mid = (left+right)/2;
    print(2*node, left, mid);
    print(2*node+1, mid+1, right);
}

int main() {
    scanf("%s", str+1);
    n = strlen(str+1);
    
    build(1, 1, n);
    //print(1, 1, n);

    int m;
    int a, b;
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", query(1, 1, n, a, b-1));
    }
}


