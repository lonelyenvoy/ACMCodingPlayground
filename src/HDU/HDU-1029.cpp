/**
 * Created by LonelyEnvoy on 2017-3-12.
 * Ignatius and the Princess IV
 * Keywords: STL map的简单使用
 */

#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    map<int, int> numbersMap;

    int n;
    int input;
    int* numbers;
    map<int, int>::iterator itr;
    int result;
    int occurTimes;
    char abandonedChar;
    while (cin >> n){
        numbers = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> input;
            numbers[i] = input;
            itr = numbersMap.find(numbers[i]);
            if (itr == numbersMap.end()) {
                numbersMap.insert(make_pair(input, 1));
            } else {
                occurTimes = ++itr->second;
                if (occurTimes >= (n + 1) / 2) { // found solution
                    result = input;
                    break;
                }
            }
        }
        delete[] numbers;

        // ignore unused numbers
        while ((abandonedChar = getchar()) != '\n' && abandonedChar != '\r') {}

        // output result
        cout << result << endl;

        // clear
        numbersMap.clear();
    }
}