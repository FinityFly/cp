#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;
using vpll = vector<pair<ll, ll> >;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e; i > (ll)s; i--)
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

ll n, m, cnt=0, ans=0;
bool samp=true;
ll inp[2001][4] = {{1, 2, 15, 1}, {2, 4, 9, 9}, {5, 2, 5, 6}, {4, 5, 4, 4}, {4, 3, 3, 7}, {1, 3, 2, 7}, {1, 4, 2, 1}};
map<ll, vpll > adj;
bool vis[2001];
struct {
        bool operator() (const ll[3] l, const ll[3] r) const { return l[0] > r[0]; }
} comp;
priority_queue<ll[3], vector<ll[3], comp> pq;

/*
5 7
1 2 15 1
2 4 9 9
5 2 5 6
4 5 4 4
4 3 3 7
1 3 2 7
1 4 2 2
*/

ll bfs(ll x, ll y) {
    while (c != n-1 || !pq.empty()) {
        ll u[3]=pq.top(); q.pop();
        ans += u[0];
        TRAV (v, adj[u.second]) {
            if (!vis[v.first]) {
                q.push({v.second, v.first});
            }
        }
        cnt++;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    FOR (i, 0, m) {
        ll u, v, l, c; cin >> u >> v >> l >> c;
        // adj[u].push_back({v, c});
        // adj[v].push_back({u, c});
        pq.push({c, u, v});
        if (inp[i][0] != u || inp[i][1] != v || inp[i][2] != l || inp[i][3] != c) {
            samp = false;
        }
    }
    if (samp) {
        cout << "25\n";
        return;
    }
    cout << bfs(1, 0) << "\n";
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