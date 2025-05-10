#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int atotal=0, btotal=0;
    int output=0;
    for (int i = 0; i < n; ++i) {
        atotal += a[i];
        btotal += b[i];
        if (atotal == btotal) {
            output = i+1;
        }
    }
    cout << output << "\n";
    return 0;
}