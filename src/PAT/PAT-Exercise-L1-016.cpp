/**
 * Created by LonelyEnvoy on 2017-3-23.
 * L1-016. 查验身份证
 * Keywords: 水题
 */


#include <iostream>
#include <string>
using namespace std;

int main() {

    const int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    const char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    bool ok = true;
    bool isNum;
    string id;
    int T;
    cin >> T;
    while (T--) {
        isNum = true;
        cin >> id;

        int sum = 0;

        for (int i = 0; i < 17; i++) {
            sum += (id[i] - '0') * weight[i];
        }
        sum %= 11;

        if (id[17] != m[sum]) {
            ok = false;
            cout << id << endl;
        }
    }
    if (ok) {
        cout << "All passed" << endl;
    }
}