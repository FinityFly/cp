#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    int dif[n+1];
    fill(dif, dif+n+1, 0);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        dif[a]++;
        dif[b]--;
    }
    int count = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += dif[i];
        if (cur == 0) {
            ++count;
        }
    }
    cout << count << " " << n-count << "\n";
    return 0;
}