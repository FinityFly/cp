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

template <class T>
struct binary_indexed_tree {
    vector<T> bit;
    ll size;

    binary_indexed_tree(const vector<T> &a) {
        size = a.size();
        bit.assign(size + 1, T());
        for (ll i = 0; i < size; i++) {
            update(i, a[i]);
        }
    }

    T query(ll r) {
        T ret = 0;
        for (ll i = r + 1; i > 0; i -= i & -i) {
            ret = ret + bit[i];
        }
        return ret;
    }

    T query(ll l, ll r) { 
        return query(r) - query(l - 1);
    }

    void update(ll index, T delta) {
        for (ll i = index + 1; i <= size; i += i & -i) {
            bit[i] = bit[i] + delta;
        }
    }
};

struct order_statistic_tree {
    vector<pll> ost;
    ll size;

    order_statistic_tree(const vector<ll> &a) {
        size = a.size();
        ost.assign(4*size + 1, {ll(), ll()});
        for (ll i = 1; i <= size; i++) {
            insert(1, a[i]);
        }
    }

    ll query(ll k) {
        ll node = 1;
        while (node < size) {
            if ((ost[node].first == 0 && ost[node].second == 0) || k == ost[node].first) {
                break;
            } else if (k < ost[node].first) {
                node *= 2;
            } else {
                node = node * 2 + 1;
            }
        }
        return ost[node].second;
    }

    void insert(ll index, ll v) {
        if (ost[index].first == 0 && ost[index].second == 0) {
            ost[index] = {v, 1};
            return;
        }
        if (v == ost[index].first) {
            ost[index].second++;
        } else if (v < ost[index].first) {
            ost[index].second++;
            insert(index * 2, v);
        } else {
            insert(index * 2 + 1, v);
        }
    }
};

void solve() {
    cin >> n >> m;
    vll arr(n);
    FOR (i, 1, n+1) cin >> arr[i];
    binary_indexed_tree<ll> bit(arr);
    order_statistic_tree ost(arr);
    FOR (i, 1, n+1) {
        cout << ost.ost[i].first << " " << ost.ost[i].second << "\n";
    }
    cout << "\n";
    while (m--) {
        char c; cin >> c;
        if (c == 'C') {
            ll x, v; cin >> x >> v;
            bit.update(x, v-arr[x]);
            ost.insert(1, v);
        } else if (c == 'S') {
            ll l, r; cin >> l >> r;
            cout << bit.query(l, r) << "\n";
        } else {
            ll v; cin >> v;
            cout << ost.query(v) << "\n";
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