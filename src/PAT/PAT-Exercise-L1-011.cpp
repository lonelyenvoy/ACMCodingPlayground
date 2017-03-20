/**
 * Created by LonelyEnvoy on 2017-3-21.
 * L1-011. A-B
 * Keywords: 简单字符串处理
 */

#include <cstdio>
using namespace std;

#define MAX 10001

int main() {
    char a[MAX];
    char b[MAX];
    scanf("%[^\n]", a);
    getchar(); // ignore \n
    scanf("%[^\n]", b);

    int alen;
    int blen = 0;
    while (b[blen] != '\0') {
        blen++;
    }

    for (int i = 0; i < MAX; i++) {
        if (a[i] == '\0') {
            alen = i + 1;
            break;
        }
        for (int j = 0; j < blen; j++) {
            if (a[i] == b[j]) {
                a[i] = 1; // removed flag
            }
        }
    }

    for (int i = 0; i < alen; i++) {
        if (a[i] == 1) {
            continue;
        }
        printf("%c", a[i]);
    }
    printf("\n");
}
