#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int av[1000001], psa[1000002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> av[i];
    }
    psa[0] = 0;
    for (int i = 1; i <= n; ++i) {
        psa[i] = psa[i-1] + av[i-1];
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (psa[b] - psa[a-1])/(b-a+1) << "\n";
    }

    return 0;
}