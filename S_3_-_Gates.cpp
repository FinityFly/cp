#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int g, p, output=0;
    cin >> g >> p;
    set<int> airport;
    for (int i = 0; i < p; ++i) {
        airport.insert(-i);
    }
    for (int i = 0; i < p; ++i) {
        int a;
        cin >> a;
        --a;
        if (airport.lower_bound(-a) == airport.end()) {
            cout << i << "\n";
            return 0;
        }
        airport.erase(airport.lower_bound(-a));
    }
    cout << p << "\n";
    return 0;
}