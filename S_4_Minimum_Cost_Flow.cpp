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
typedef unordered_map<ll, ll> mll;
typedef unordered_set<ll> sll;

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

struct Edge {
    ll u, v, w;
    ll id;
    bool og;
    Edge(ll u, ll v, ll w, ll id, bool og) : u(u), v(v), w(w), id(id), og(og) {}
};

ll n, m, d;
vpll adj[100001], mst[100001];
vector<Edge> edges;

// DSU
ll p[MM];
void mset(ll d) {p[d]=d;}
ll fset(ll d) {if(d!=p[d])p[d]=fset(p[d]);return p[d];}
void uni(ll x, ll y) {ll a=fset(x),b=fset(y);if(a!=b)p[a]=b;}

void solve() {
    cin >> n >> m >> d;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    for (ll i = 1; i <= n; ++i) {
        mset(i);
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        edges.push_back(Edge(a, b, c, i, (i < n-1)));
    }
    sort(all(edges), [](const Edge &a, const Edge &b) {
        if (a.w == b.w) {
            return a.og > b.og;
        } else {
            return a.w < b.w;
        }
    });
    // construct mst
    ll og_cnt = 0, og_cost = 0, edges_cnt = 0, heaviest = 0;
    for (auto edge : edges) {
        heaviest = max(heaviest, edge.w);
        if (edges_cnt == n - 1) break;
        if (fset(edge.u) != fset(edge.v)) {
            uni(edge.u, edge.v);
            edges_cnt++;
            if (edge.og) {
                og_cnt++;
                og_cost += edge.w;
            }
        } 
    }
    if (d == 0) {
        cout << (n-1)-og_cnt << "\n";
    } else {
        bool replace = false;
        for (ll i = 0; i < m; ++i) {
            // if the edge's weight is less than or was in the original MST and has a weight equal to, then we add it into the MST like in the standard algorithm. However, if the weight of the edge is <= D and is also an old edge, then it can replace one of the edges we used, thus decreasing the number of days required by 1
            if (edges[i].w < heaviest || (edges[i].og) && edges[i].w == heaviest) {
                mst[edges[i].u].push_back({edges[i].v, edges[i].w});
                mst[edges[i].v].push_back({edges[i].u, edges[i].w});
            }
            // if the weight of the edge is <= D and is also an old edge, then it can replace one of the edges we used, thus decreasing the number of days required by 1
            if (edges[i].w <= d && edges[i].og) {
                replace = true;
                break;
            }
        }
        cout << (n-1) - og_cnt - replace << "\n"; 
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
