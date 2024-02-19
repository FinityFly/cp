#include <bits/stdc++.h>
using namespace std;

/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "*";
        }
        for (int j = 0; j < n*2 - m*2; ++j) {
            cout << " ";
        }
        for (int j = 0; j < m; ++j) {
            cout << "*";
        }
        if (n/2 > i) {
            m += 2;
        } else {
            m -= 2;
        }
        cout << "\n";
    }
    return 0;
}