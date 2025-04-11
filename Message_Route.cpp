#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vector<ll> > vvll;
typedef vector< pair<ll, ll> > vpll;
typedef map<ll, ll> mll;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e-1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
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

ll n, m;
bool vis[MM];
vector<ll> adj[MM];
ll parent[MM];
ll p[MM];
void mset(ll d) {p[d]=d;}
ll fset(ll d) {if(d!=p[d])p[d]=fset(p[d]);return p[d];}
void uni(ll x, ll y) {ll a=fset(x),b=fset(y);if(a!=b)p[a]=b;}

void solve() {
    memset(p, 0, sizeof(p));
    cin >> n >> m;
    FOR (i, 0, n) {
        mset(i);
    }
    FOR (i, 0, m) {
        ll u, v; cin >> u >> v;
        uni(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (fset(n) != fset(1)) {
        cout << "IMPOSSIBLE\n";
    } else {
        bool found = 0;
        queue<ll> q;
        memset(vis, 0, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            ll u = q.front(); q.pop();
            if (u == n) {
                found = 1;
                break;
            }
            TRAV (v, adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (found) {
            vll path;
            ll x = n;
            while (x != -1) {
                path.push_back(x);
                x = parent[x];
            }
            reverse(all(path));
            cout << path.size() << "\n";
            FOR (i, 0, path.size()) {
                cout << path[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
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
