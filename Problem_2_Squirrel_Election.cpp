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

ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template <class T>
string to_string(T s, T e) {
    if (s == e) return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e) ret += ", " + to_string(*s++);
    return ret + "]";
}

#define MM 5001
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

ll n, minp=0;
ll voters[MM], points[MM];
ll dp[MM][MM];
bool dp_solved[MM][MM];

ll min_voters(ll index, ll n_points) {
    if (dp_solved[index][n_points]) {
        return dp[index][n_points];
    }
    if (n_points <= 0) {
        return 0;
    } else if (index == n && n_points > 0) {
        return LONG_LONG_MAX;
    }
    ll option_leave = min_voters(index + 1, n_points);
    ll option_take = voters[index] + min_voters(index + 1, n_points - points[index]);
    if (option_take < 0) option_take = LONG_LONG_MAX;
    dp_solved[index][n_points] = true;
    dp[index][n_points] = min(option_leave, abs(option_take));
    return dp[index][n_points];
}

void solve() {
    cin >> n;
    FOR (i, 0, n) {
        ll v, p; cin >> v >> p;
        voters[i] = floor(v/2)+1;
        points[i] = p;
        minp += p;
    }
    minp = floor(minp/2)+1;
    cout << min_voters(0, minp) << "\n";
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