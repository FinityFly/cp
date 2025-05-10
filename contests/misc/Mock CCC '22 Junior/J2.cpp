#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int x[n], y[n];
    int t1=0, t2=0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if (a > x[i]) {
            t1 += 1;
        } else {
            t1 += 2;
        }
        if (b > y[i]) {
            t2 += 1;
        } else {
            t2 += 2;
        }
    }
    if (t1 > t2) {
        cout << "Tommy wins!" << "\n";
    } else if (t1 < t2) {
        cout << "Andrew wins!" << "\n";
    } else {
        cout << "Tie!\n";
    }
    
    return 0;
}