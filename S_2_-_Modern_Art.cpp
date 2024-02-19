#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    int rows[m], cols[n];
    fill(rows, rows+m, 0);
    fill(cols, cols+n, 0);
    for (int i = 0; i < k; ++i) {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'R') {
            ++rows[b-1];
        } else {
            ++cols[b-1];
        }
    }
    int output = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((rows[i] + cols[j]) % 2 == 1)
                ++output;
        }
    }
    cout << output << "\n";
    return 0;
}