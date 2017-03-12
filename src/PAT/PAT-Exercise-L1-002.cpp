/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L1-002. 打印沙漏
 * Keywords: 水题
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    char c;
    cin >> N >> c;
    int lines = 2 * (int)(0.5 * sqrt(2 * (N + 1)) - 1) + 1;
    int stars = lines;
    int spaces = 0;
    bool passedHalf = false;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << ' ';
        }
        for (int j = 0; j < stars; j++) {
            cout << c;
        }
        if (stars >= 3 && !passedHalf) {
            stars -= 2;
            spaces += 1;
        } else {
            passedHalf = true;
            stars += 2;
            spaces -= 1;
        }
        cout << '\n';
    }
    lines = (lines - 1) / 2;
    int starsLeft =  N - ((2 * lines * lines + 4 * lines + 1));
    cout << starsLeft << endl;
}
