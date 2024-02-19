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

ll h, w;
bool obs[1001][1001];
ll dp[1001][1001];
bool dp_solved[1001][1001];

ll num_ways(ll x, ll y) {
	if (x == h-1 && y == w-1) return 1;
	if (dp_solved[x][y]) return dp[x][y];
	ll ans=0;
	if (!obs[x+1][y] && x+1 < h) {
		ans += num_ways(x+1, y)%MOD;
	}
	if (!obs[x][y+1] && y+1 < w) {
		ans += num_ways(x, y+1)%MOD;
	}
	dp_solved[x][y] = true;
	return dp[x][y] = ans%MOD;
}

void solve() {
    cin >> h >> w;
	FOR (i, 0, h) {
		FOR (j, 0, w) {
			char c; cin >> c;
			if (c == '.') obs[i][j] = false;
			else obs[i][j] = true;
		}
	}
	cout << num_ways(0, 0)%MOD << "\n";;
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