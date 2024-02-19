#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

bool u[1000001];
int psa[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        u[a] = true;
    }
    psa[0] = 0;
    for (int i = 1; i <= 1000000; ++i) {
        psa[i] = psa[i-1] + u[i-1];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        cout << f - psa[f] << '\n';
    }
    return 0;
}