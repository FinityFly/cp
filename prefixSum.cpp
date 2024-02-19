#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int prefixSum[1005];

void fillPrefixSum(int arr[], int n) {
    prefixSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    fillPrefixSum(arr, n);
    for (int i = 0; i <= n; ++i) {
        cout << prefixSum[i] << ' ';
    }
    cout << "\n";

    int l, r;
    cin >> l >> r;
    int ans = prefixSum[r] - prefixSum[l-1];
    cout << ans << "\n";

    return 0;
}