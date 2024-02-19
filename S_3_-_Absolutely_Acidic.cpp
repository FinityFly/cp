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

ll n, r, cnt[1001], h1=0, h2=0;
vector<ll> high1, high2;

void solve() {
    cin >> n;
    FOR (i, 0, n) {
        cin >> r;
        cnt[r]++;
        if (cnt[r] >= h1) {
            if (cnt[r] > h1) high1.clear();
            h1 = cnt[r];
            high1.push_back(r);
        }
    }
    FOR (i, 0, 1000) {
        if (cnt[i] >= h2 && cnt[i] < h1) {
            if (cnt[i] > h2) high2.clear();
            h2 = cnt[i];
            high2.push_back(i);
        }
    }
    if (high1.size() == 1) {
        if (high2.size() == 1) cout << abs(high1[0]-high2[0]) << "\n";
        else {
            ll out=0;
            TRAV (i, high2)
                if (abs(i-high1[0]) > out) out = abs(i-high1[0]);
            cout << out << "\n";
        }
    } else {
        ll r=0, l=INT_MAX;
        TRAV (i, high1)
            if (r < i) r = i;
        TRAV (i, high1)
            if (i < l && i < r) l = i;
        cout << abs(l-r) << "\n";
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