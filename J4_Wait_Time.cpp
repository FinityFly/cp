#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, r[101], w[101], t=0;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'R') {
            r[b] = t;
            t++;
        } else if (a == 'S') {
            w[b] += t - r[b];
            r[b] = -1;
            t++;
        } else {
            t += b - 1;
        }
    }
    for (int i = 1; i <= 100; ++i) {
        if (r[i] != -1 && r[i] != 0) {
            cout << i << " " << -1 << "\n";
        } else if (r[i] == -1) {
            cout << i << " " << w[i] << "\n";
        }
    }

    return 0;
}