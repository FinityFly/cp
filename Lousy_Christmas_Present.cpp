#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int c[n], out=0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, l=0, length=n;
        cin >> a >> b;
        bool possible = true;
        for (int j = 0; j <= n; ++j) {
            if (c[j] == a) {
                l=j;
                break;
            } else if (j == n) {
                possible = false;
            }
        }
        if (possible) {
            for (int j = n; j >= l; --j) {
                if (c[j-1] == b) {
                    length = j-l;
                    break;
                } else if (j == l) {
                    possible = false;
                }
            }
            out = max(out, length);
        }
    }
    cout << out << "\n";
    return 0;
}