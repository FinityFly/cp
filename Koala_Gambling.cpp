#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */
int t, n, arr[601];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    for (int x = 0; x < t; ++x) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr+n, greater<int>());
        if (n % 2 == 1) {
            cout << arr[0];
            for (int i = 1; i < n; ++i) {
                cout << " " << arr[i];
            }
            cout << "\n";
        } else {
            if (arr[0] == arr[n-1]) {
                cout << "-1\n";
                continue;
            }
            int lower[(int) floor(n/2)], upper[(int) floor(n/2)+1];
            for (int i = 0; i < n; ++i) {
                if (i < floor(n/2)) {
                    upper[i] = arr[i];
                } else {
                    lower[i-(int) floor(n/2)] = arr[i];
                }
            }
            cout << upper[0];
            for (int i = 1; i < n; ++i) {
                if (i % 2 == 0) {
                    cout << " " << upper[i/2];
                } else {
                    cout << " " << lower[(i-1)/2];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}