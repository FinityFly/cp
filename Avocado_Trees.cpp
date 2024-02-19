#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int h[1000001], v[1000001], psa[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, s;
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> v[i];
    }
    psa[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i-1] <= s) {
            psa[i] = psa[i-1] + v[i-1];
        } else {
            psa[i] = psa[i-1];
        }
    }
    int max = -1;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (max < psa[b] - psa[a-1]) {
            max = psa[b] - psa[a-1];
        }
    }
    cout << max << "\n";
    return 0;
}