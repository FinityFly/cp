#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m;
int a[100001];

bool check (ll lim) {
    ll sum=0;
    int cnt=1;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] > lim) {
            ++cnt;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return (cnt <= m);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll lo=0, hi=0, ans=0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        lo = max(lo, (ll)a[i]);
        hi += a[i];
    }
    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}