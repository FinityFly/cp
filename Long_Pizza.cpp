#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

ll arr[10000000], dif[10000001], psa[10000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y, r;
    cin >> n >> x >> y >> r;
    for (int i = 0; i < r; ++i) {
        int l, r;
        cin >> l >> r;
        dif[l]++;
        dif[r+1]--;
    }
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        arr[i] = dif[i] + arr[i-1];
    }
    psa[0] = 0;
    for (int i = 1; i <= n; ++i) {
        psa[i] = psa[i-1] + arr[i-1];
    }
    cout << psa[y+1] - psa[x] << "\n";
    return 0;
}