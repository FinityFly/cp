#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    long duke=0, alice=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long a;
        cin >> a;
        if (a % 2 == 0) {
            duke += a/2;
        } else {
            alice += (a+1)/2;
        }
    }
    if (duke > alice) {
        cout << "Duke\n";
    } else {
        cout << "Alice\n";
    }
    return 0;
}