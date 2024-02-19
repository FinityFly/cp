#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, s, h;
    cin >> t >> s >> h;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << '*';
            cout << string(s, ' ');
        }
        cout << "*\n";
    }
    cout << string(s*2+3, '*') << "\n";
    for (int i = 0; i < h; ++i) {
        cout << string(floor((s*2+3)/2), ' ');
        cout << "*\n";
    }
    return 0;
}