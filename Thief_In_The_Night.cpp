#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int cd[4][10000], psa[5][10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int f, r, q;
    cin >> f >> r;
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> cd[i][j];
        }
    }
    for (int j = 0; j < f; ++j) {
        psa[j][0] = 0;
        for (int i = 1; i <= r; ++i) {
            psa[j][i] = psa[j][i-1] + cd[j][i-1];
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << psa[c-1][b] - psa[c-1][a-1] << "\n";
    }
    return 0;
}