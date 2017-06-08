/**
 * Created by LonelyEnvoy on 2017-6-8.
 * Quadtree
 * Keywords: 四分树，dfs，进制转换
 */

// 需注意本题的数据范围，一开始segment fault了很多次，是由于str数组开得不够大，下标访问越界。
// 出现此类错误时务必仔细计算边界大小，以免debug了很久都找不出具体错误。
// 另外，ZOJ不靠谱，经测试明显有错的代码（在其他OJ的相同题目上Runtime Error）竟然可以AC。

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define rep(i,a,n) for (int i = a; i < n; ++i)
#define erep(i,a,n) for (int i = a; i <= n; ++i)
#define per(i,a,n) for (int i = n-1; i >= a; --i)

#define MAX 513

char str[MAX * MAX * 2];
int n;
bool g[MAX][MAX]; // B -> 1, W -> 0

int build(int r, int c, int len, int pos) {
    if (str[pos] != 'Q') {
        bool color = str[pos] == 'B';
        rep(i,r,r+len) {
            rep(j,c,c+len) {
                g[i][j] = color; 
            }
        }
        return pos + 1;
    }
    
    len /= 2;
    int pos1 = build(r, c, len, pos + 1);
    int pos2 = build(r, c+len, len, pos1);
    int pos3 = build(r+len, c, len, pos2);
    return     build(r+len, c+len, len, pos3);
}

char buffer[20];
void printHex(int r) {
    int sum;
    for (int k = 0; k < n; k += 8) {
        sum = 0;
        rep(i,0,8) {
            sum += g[r][k+i] * pow(2,i);
        }
        sprintf(buffer, "0x%02x,", sum);
        printf("%s", buffer);
    }
    printf("\n");
}

void debug() {
    rep(i,0,n) {
        rep(j,0,n) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d%s", &n, str);
    build(0, 0, n, 0);

    //debug();

    printf("#define quadtree_width %d\n", n);
    printf("#define quadtree_height %d\n", n);
    printf("static char quadtree_bits[] = {\n");
    rep(i,0,n) {
        printHex(i);
    }
    printf("};\n");
}


