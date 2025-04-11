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

ll n, m;
vpll friends;
vector<pair<ll, pll>> edges;

ll p[100001];
void mset(ll d) {p[d]=d;}
ll fset(ll d) {if(d!=p[d])p[d]=fset(p[d]);return p[d];}
void uni(ll x, ll y) {ll a=fset(x),b=fset(y);if(a!=b)p[a]=b;}

void solve() {
    cin >> n >> m;
    FOR (i, 1, n+1) {
        ll f; cin >> f;
        friends.push_back({f, i});
        mset(i);
    }
    FOR (i, 0, m) {
        ll u, v; cin >> u >> v;
        uni(u, v);
    }
    sort(all(friends));
    FOR (i, 0, n-1) {
        edges.push_back({friends[i+1].first-friends[i].first, {friends[i].second, friends[i+1].second}});
    }
    sort(all(edges), [](const pair<ll, pll>& a, const pair<ll, pll>& b) {
        return a.first < b.first;
    });
    ll ans = 0;
    FOR (i, 0, edges.size()) {
        if (fset(edges[i].second.first) == fset(edges[i].second.second)) continue;
        ans += edges[i].first;
        uni(edges[i].second.first, edges[i].second.second);
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
