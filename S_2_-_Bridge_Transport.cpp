#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int w, n, sum=0;
int r[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        sum += r[i];
        if (i >= 4)
            sum -= r[i-4];
        if (sum > w) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}