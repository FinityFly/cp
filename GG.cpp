#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string g;
    int n;
    cin >> g >> n;
    int psa[g.length()+1];
    psa[0] = 0;
    for (int i = 1; i <= g.length()+1; ++i) {
        if (g[i-1] == 'G') {
            psa[i] = psa[i-1] + 1;
        } else {
            psa[i] = psa[i-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << "\n";
    }
    return 0;
}