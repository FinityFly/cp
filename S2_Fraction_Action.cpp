#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d, a, b;
    cin >> n >> d;
    a = n % d;
    b = d;
    if (a == 0) {
        cout << floor(n/d) << "\n";
    } else {
        for (int i = a; i > 1; --i) {
            if (a % i == 0 && b % i == 0) {
                a /= i; b /= i;
            }
        }
        if (floor(n/d) != 0) {
            cout << floor(n/d) << " ";
        }
        cout << a << "/" << b << "\n";
    }
    return 0;
}