/**
 * Created by LonelyEnvoy on 2017-3-12.
 * L2-014. 列车调度
 * Keywords: STL set的简单应用
 * Limits: High run-time efficiency required
 */

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> rails;
    set<int>::iterator itr;
    int N;
    cin >> N;
    int train;
    cin >> train;
    rails.insert(train);
    for (int i = 1; i < N; i++) {
        cin >> train;
        // find the closest element bigger than train
        itr = rails.lower_bound(train);
        if (itr != rails.end()) { // found
            // replace it
            rails.erase(itr);
            rails.insert(train);
        } else { // all elements are smalller than train
            // create a new rail
            rails.insert(train);
        }
    }
    cout << rails.size() << endl;
}
