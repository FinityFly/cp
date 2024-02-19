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
using mll = map<ll, ll>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e-1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

template <class T>
string to_string(T s, T e) {
    if (s == e) return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e) ret += ", " + to_string(*s++);
    return ret + "]";
}

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

int n, m, t;
map<int, int> c, dp[100001];
vector<int> p;

int max_treats(int index, int disLeft) {
    if (dp[index][disLeft]) return dp[index][disLeft];
    if (index == n+1) return 0;
    int option_take=0, option_skip=0;
    if (disLeft-(p[index]-p[index-1])*2 >= 0)
        option_skip = max_treats(index+1, disLeft-(p[index]-p[index-1])*2);
    if (disLeft-t-(p[index]-p[index-1])*2 >= 0)
        option_take = max_treats(index+1, disLeft-t-(p[index]-p[index-1])*2)+c[p[index]];
    dp[index][disLeft] = max(option_take, option_skip);
    return max(option_take, option_skip);
}

void solve() {
    cin >> n >> m >> t;
    p.push_back(0);
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        p.push_back(a);
        c[a] = b;
    }
    sort(all(p));
    cout << max_treats(1, m) << "\n";
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