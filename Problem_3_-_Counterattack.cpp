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

ll n, m, ans=0;
vector<vector<ll>> adj(5001, vector<ll>(5001));
bool vis[5001];
ll dis[5001], parent[5001];
vector<ll> path;

void travPath(ll i) {
    if (parent[i] == -1) {
        path.push_back(i);
        return;
    }
    travPath(parent[i]);
    path.push_back(i);
}

ll dijk(ll a) {
    queue<ll> q;
    fill(dis, dis+5001, INT_MAX);
    fill(parent, parent+5001, -1);
    fill(vis, vis+5001, false);
    q.push(a);
    dis[a] = 0;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        vis[u] = true;
        FOR (v, 1, n+1) {
            if (!vis[v] && dis[u] != INT_MAX && adj[u][v]) {
                if (dis[u] + adj[u][v] < dis[v]) {
                    dis[v] = dis[u] + adj[u][v];
                    parent[v] = u;
                    q.push(v);
                } 
            }
        }
    }
    return dis[n];
}

ll getMinDist(ll x, ll y, vector<vector<ll>> grid) {
    grid[x][y] = 0;
    grid[y][x] = 0;
    // FOR (i, 1, n+1) {
    //     FOR (j, 1, n+1) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    queue<ll> q;
    fill(dis, dis+5001, INT_MAX);
    fill(parent, parent+5001, -1);
    fill(vis, vis+5001, false);
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        vis[u] = true;
        FOR (v, 1, n+1) {
            if (!vis[v] && dis[u] != INT_MAX && grid[u][v]) {
                if (dis[u] + grid[u][v] < dis[v]) {
                    dis[v] = dis[u] + grid[u][v];
                    parent[v] = u;
                    q.push(v);
                } 
            }
        }
    }
    return dis[n];
}

void solve() {
    cin >> n >> m;
    FOR (i, 0, m) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    ll d1=dijk(1);
    travPath(n);
    FOR (i, 0, path.size()-1) {
        ll d2 = getMinDist(path[i], path[i+1], adj);
        if (d2 != d1 && d2 != INT_MAX) ans = max(ans, d2);
    }
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