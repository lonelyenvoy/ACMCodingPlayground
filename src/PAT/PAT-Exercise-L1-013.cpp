/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L1-013. 计算阶乘和
 * Keywords: 水题，递归的简单应用
 */


#include <iostream>
#include <map>
using namespace std;

map<int, int> factorialMap;

int factorial(int n) {
    if (n == 1) return 1;
    if (factorialMap.find(n) != factorialMap.end()) {
        return factorialMap[n];
    }
    int result = n * factorial(n - 1);
    factorialMap.insert(make_pair(n, result));
    return result;
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    cout << sum << endl;
}
