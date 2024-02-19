#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e; i > (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

template <class T>
string to_string(T s, T e) {
    if (s == e) return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e) ret += ", " + to_string(*s++);
    return ret + "]";
}

#define MM 100001
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

ll n, p[100001][3];
bool dp_solved[100001][3];
ll dp[100001][3];

ll max_points(ll d, ll prev) {
    if (d == n+1) return 0;
    if (dp_solved[d][prev]) return dp[d][prev];
    ll maxp = 0;
    if (prev != 0)
        maxp = max(maxp, max_points(d+1, 0)+p[d][0]);
    if (prev != 1)
        maxp = max(maxp, max_points(d+1, 1)+p[d][1]);
    if (prev != 2)
        maxp = max(maxp, max_points(d+1, 2)+p[d][2]);
    dp_solved[d][prev] = true;
    return dp[d][prev] = maxp;
}

void solve() {
    cin >> n;
    FOR (i, 1, n+1) cin >> p[i][0] >> p[i][1] >> p[i][2];
    ll ans = 0;
    FOR (i, 0, 3)
        ans = max(ans, max_points(1, i));
    cout << ans << "\n";
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}