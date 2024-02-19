#include <bits/stdc++.h>
using namespace std;

/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, c, output=0;
    cin >> t >> c;
    int chores[c];
    for (int i = 0; i < c; i++) {
        cin >> chores[i];
    }
    sort(chores, chores + c);
    int minspent = 0, i = 0;
    while (minspent + chores[i] <= t || i == c) {
        minspent += chores[i];
        ++output;
        ++i;
    }
    cout << output << "\n";
    return 0;
}