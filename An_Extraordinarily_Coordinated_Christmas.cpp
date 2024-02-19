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

ll n, q, fardis, far;
vpll adj[100001];
ll dis[100001], dp[100001];
bool vis[100001];

void bfs(ll a) {
    fardis=0;
    queue<ll> q;
    fill(vis, vis+100001, false);
    fill(dis, dis+100001, 0);
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        if (fardis < dis[u]) {
            fardis = dis[u];
            far=u;
        }
        TRAV (v, adj[u]) {
            if (!vis[v.first]) {
                vis[v.first] = true;
                dis[v.first] = dis[u] + v.second;
                q.push(v.first);
            }
        }
    }
}

void solve() {
    cin >> n >> q;
    FOR (i, 0, n-1) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bfs(1);
    bfs(far);
    bfs(far);
    FOR (i, 0, q) {
        ll x, maxd=0; cin >> x;
        FOR (j, 0, n)
            maxd = max(maxd, abs(dis[x] - dis[j]));
        cout << maxd << "\n";
    }
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