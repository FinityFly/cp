#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    int h[n];
    if (x > n || n - x == 1 || (n - x) % 2 == 1) {
        cout << "-1\n";
        return 0;
    }
    h[0] = 0;
    h[n] = 0;
    for (int i = 0; i < n-1; ++i) {
        if (x > 0) {
            if (h[i] == 0) {
                h[i+1] = 0;
            } else {
                h[i+1] = 1;
            }
            --x;
        } else {
            if (h[i] == 0) {
                h[i+1] = 1;
            } else {
                h[i+1] = 0;
            }
        }
    }

    cout << h[0];
    for (int i = 0; i < n-1; ++i) {
        cout << ' ' << h[i];
    }
    cout << "\n";
    return 0;
}