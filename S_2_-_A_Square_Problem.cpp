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

ll n, grid[37][37], freqr[91], freqc[91];

void solve() {
    cin >> n;
    FOR (i, 0, n) {
        fill(freqr, freqr+91, 0);
        string s; cin >> s;
        FOR (j, 0, n) {
            grid[i][j] = (int) s[j]-'0';
            if (freqr[grid[i][j]] > 0) {
                cout << "No\n";
                return;
            } else {
                freqr[grid[i][j]]++;
            }
        }
    }
    FOR (i, 0, n) {
        fill (freqc, freqc+91, 0);
        FOR (j, 0, n) {
            if (freqc[grid[j][i]] > 0) {
                cout << "No\n";
                return;
            } else {
                freqc[grid[j][i]]++;
            }
        }
    }
    FOR (i, 0, n-1) {
        if (grid[0][i] >= grid[0][i+1]) {
            cout << "Latin\n";
            return;
        }
        if (grid[i][0] >= grid[i+1][0]) {
            cout << "Latin\n";
            return;
        }
    }
    cout << "Reduced\n";
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