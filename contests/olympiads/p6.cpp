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

ll n, m, x, y, ans=-1;
bool grid[201][201];
ll vis[201][201];
pll flow[8] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

void longest (ll u, ll v, ll t) {
    queue<pair<pll, ll>> q;
    q.push({{u, v}, t});
    while (!q.empty()) {
        pair<pll, ll> cur = q.front(); q.pop();
        ans = cur.second;
        if (vis[cur.first.first][cur.first.second] == -1) vis[cur.first.first][cur.first.second] = cur.second;
        else vis[cur.first.first][cur.first.second] = min(vis[cur.first.first][cur.first.second], cur.second);
        FOR (i, 0, 8) {
            ll newu = cur.first.first+flow[i].first, newv = cur.first.second+flow[i].second;
            if (vis[newu][newv] == -1 && !grid[newu][newv] && newu > 0 && newv > 0 && newu <= n && newv <= m) {
                q.push({{newu, newv}, cur.second+1});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> x >> y;
    FOR (i, 1, m+1) {
        FOR (j, 1, n+1) {
            char c; cin >> c;
            if (c == '*') {
                grid[j][m-i+1] = true;
            }
        }
    }
    swap(n, m);
    FOR (i, 0, n+1) {
        fill(vis[i], vis[i]+m+1, -1);
    }
    longest(x, y, 0);
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