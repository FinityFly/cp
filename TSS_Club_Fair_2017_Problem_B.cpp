#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
ll n, q;
ld d[186739];

ld dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow(abs(x2-x1), 2.0) + pow(abs(y2-y1), 2.0));
}

int binary_search(double x) {
    ll l=0, h=n, ind=n;
    for (int i = 0; i < 18; ++i) {
        if ((ld) d[(l+h)/2] > x)
            h = (l+h)/2;
        else if ((ld) d[(l+h)/2] < x)
            l = (l+h)/2;
        else {
            ind = (l+h)/2;
            break;
        }
    }
    for (int i = ind+1; i < n; i++) {
        if (d[i] == x) ind = i;
        else break;
    }
    return ind;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        d[i] = dist(x, y, 0, 0);
    }
    sort(d, d+n);
    for (int i = 0; i < q; ++i) {
        ll r;
        cin >> r;
        cout << binary_search(*upper_bound(d, d+n, r)) << "\n";
    }
    return 0;
}