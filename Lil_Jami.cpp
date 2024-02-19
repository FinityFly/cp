#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, q;
    cin >> n >> k;
    int c[n];
    fill(c, c+n, 0);
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        ++c[a];
    }
    int psa[n+1];
    psa[0] = 0;
    for (int i = 1; i < n+1; ++i) {
        psa[i] = psa[i-1] + c[i-1];
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << "\n";
    }
    return 0;
}