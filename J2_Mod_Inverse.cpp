#include <bits/stdc++.h>
using namespace std;

/*
The remainder upon dividing x * n by m is 1 
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x, m;
    cin >> x >> m;
    for (long long i = m-1; i > 0; --i) {
        if (x*i % m == 1) {
            cout << i;
            return 0;
        }
    }
    cout << "No such integer exists.\n";
    return 0;
}