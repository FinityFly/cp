#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int t, n;
int a[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool isValid = true;
        for (int i = 0; i < n-2; ++i) {
            if (a[i] != 0 && a[i+1] != 0 && a[i+2] != 0) {
                if ((a[i] < a[i+1] && a[i+1] < a[i+2]) || (a[i] > a[i+1] && a[i+1] > a[i+2])) {
                    isValid = false;
                    break;
                }
            } else if ((a[i] == a[i+1] && a[i] != 0) || (a[i+1] == a[i+2] && a[i+1] != 0)) {
                isValid = false;
                break;
            }
        }
        if (isValid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}