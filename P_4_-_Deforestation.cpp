#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;
    int arr[n], psa[n+1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    psa[0] = 0;
    for (int i = 1; i <= n; ++i) {
        psa[i] = psa[i-1] + arr[i-1];
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << "\n";
    }
    return 0;
}