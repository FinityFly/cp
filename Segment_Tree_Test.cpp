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
vll arr(100001);

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

template <class T>
struct min_segment_tree {
    ll size;
    vector<T> tree;

    void build(vector<T> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v + 1, tl, tm);
            build(a, v + 2 * (tm - tl + 1), tm + 1, tr);
            tree[v] = min(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);
        }
    }

    T query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return numeric_limits<T>::max();
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return min(query(v + 1, tl, tm, l, r), query(v + 2 * (tm - tl + 1), tm + 1, tr, l, r));
    }

    void update(ll v, ll tl, ll tr, ll index, T value) {
        if (tl == tr) {
            tree[v] = value;
        } else {
            ll tm = (tl + tr) / 2;
            if (index <= tm) {
                update(v + 1, tl, tm, index, value);
            } else {
                update(v + 2 * (tm - tl + 1), tm + 1, tr, index, value);
            }
            tree[v] = min(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);
        }
    }
};

template <class T>
struct gcd_segment_tree {
    ll size;
    vector<T> tree;

    T combine(T a, T b) {
        ll g = gcd(a.first, b.first);
        return make_pair(g, ((g == a.first) ? a.second : 0) + ((g == b.first) ? b.second : 0));
    }

    void build(vll &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = make_pair(a[tl], 1);
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v + 1, tl, tm);
            build(a, v + 2 * (tm - tl + 1), tm + 1, tr);
            tree[v] = combine(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);

            // ll g = (tree[v + 1].first, tree[v + 2 * (tm - tl + 1)].first);
            // tree[v] = make_pair(g, ((g == tree[v + 1].first) ? tree[v + 1].second : 0) + ((g == tree[v + 2 * (tm - tl + 1)].first) ? tree[v + 2 * (tm - tl + 1)].second : 0));
        }
    }

    T query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return T();
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        pll ql = query(v + 1, tl, tm, l, r);
        pll qr = query(v + 2 * (tm - tl + 1), tm + 1, tr, l, r);
        return combine(ql, qr);

        // ll g = gcd(ql.first, qr.first);
        // return make_pair(g, ((g == ql.first) ? ql.second : 0) + ((g == qr.first) ? qr.second : 0));
    }

    void update(ll v, ll tl, ll tr, ll index, ll value) {
        if (tl == tr) {
            tree[v] = make_pair(value, 1);
        } else {
            ll tm = (tl + tr) / 2;
            if (index <= tm) {
                update(v + 1, tl, tm, index, value);
            } else {
                update(v + 2 * (tm - tl + 1), tm + 1, tr, index, value);
            }
            tree[v] = combine(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);

            // ll g = gcd(tree[v + 1].first, tree[v + 2 * (tm - tl + 1)].first);
            // tree[v] = make_pair(g, ((g == tree[v + 1].first) ? tree[v + 1].second : 0) + ((g == tree[v + 2 * (tm - tl + 1)].first) ? tree[v + 2 * (tm - tl + 1)].second : 0));
        }
    }
};

void solve() {
    cin >> n >> m;
    FOR (i, 0, n) cin >> arr[i];
    min_segment_tree<ll> minst;
    gcd_segment_tree<pll> gcdst;
    minst.tree.resize(4 * n); gcdst.tree.resize(4 * n);
    minst.build(arr, 0, 0, n-1); gcdst.build(arr, 0, 0, n-1);
    FOR (i, 0, m) {
        char x; ll l, r; cin >> x >> l >> r;
        if (x == 'C') {
            minst.update(0, 0, n-1, l-1, r); gcdst.update(0, 0, n-1, l-1, r);
            arr[l-1] = r;
        } else if (x == 'M') {
            cout << minst.query(0, 0, n-1, l-1, r-1) << "\n";
        } else if (x == 'G') {
            cout << gcdst.query(0, 0, n-1, l-1, r-1).first << "\n";
        } else {
            cout << gcdst.query(0, 0, n-1, l-1, r-1).second << "\n";
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