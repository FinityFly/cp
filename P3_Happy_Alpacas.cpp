#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */

int n, x;
int h[1000000];

bool isHappy(int i) {
    if ((h[i] + h[i+1]) % 2 == 0 || (h[i] == n-1 && (h[i] + h[i+1]) % 2 == 0)) {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    if (x > n || n - x == 1 || (n - x) % 2 == 1) {
        cout << "-1\n";
        return 0;
    }
    h[0] = 0;
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (x > 0) {
            h[i+1] = 0;
        } else {
            if (a == 0) {
                h[i+1] = 1;
                a = 1;
            } else {
                h[i+1] = 0;
                a = 0;
            }
        }
    }

    cout << h[0];
    for (int i = 0; i < n; ++i) {
        cout << ' ' << h[i];
    }
    cout << "\n";
    return 0;
}