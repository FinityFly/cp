#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int arr[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < 0)
            arr[i] = 0;
    }
    sort(arr, arr+n);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += arr[n-i-1];
    }
    cout << sum << "\n";
    return 0;
}