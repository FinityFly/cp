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

// #define SINGLE ;
#define MULTIPLE ;
// #define GOOGLE ;

ll getNum(ll n, ll base, ll x, ll y) {
    if (n == 1) {
        if (x == 1 && y == 1) return base;
        if (x == 2 && y == 2) return base + 1;
        if (x == 2 && y == 1) return base + 2;
        return base + 3;
    }
    ll m = (1 << (n-1)), block = 1LL << (2*(n-1));
    if (x <= m && y <= m) return getNum(n-1, base, x, y);
    if (x > m && y > m) return getNum(n-1, base + block, x - m, y - m);
    if (x > m && y <= m) return getNum(n-1, base + 2*block, x - m, y);
    return getNum(n-1, base + 3*block, x, y - m);
}

pll getCoord(ll n, ll base, ll d) {
    if (n == 1) {
        if (d == base) return {1, 1};
        if (d == base + 1) return {2, 2};
        if (d == base + 2) return {2, 1};
        return {1, 2};
    }
    ll m = (1 << (n-1)), block = 1LL << (2*(n-1));
    ll q = (d - base) / block;
    if (q == 0) {
        pll p = getCoord(n-1, base, d);
        return {p.first, p.second};
    }
    if (q == 1) {
        pll p = getCoord(n-1, base + block, d);
        return {p.first + m, p.second + m};
    }
    if (q == 2) {
        pll p = getCoord(n-1, base + 2*block, d);
        return {p.first + m, p.second};
    }
    pll p = getCoord(n-1, base + 3*block, d);
    return {p.first, p.second + m};
}

void solve() {
    ll n, q;
    cin >> n >> q;
    while (q--) {
        string s; cin >> s;
        if (s == "->") {
            ll x, y; cin >> x >> y;
            cout << getNum(n, 1, x, y) << "\n";
        } else {
            ll d; cin >> d;
            pll p = getCoord(n, 1, d);
            cout << p.first << " " << p.second << "\n";
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
