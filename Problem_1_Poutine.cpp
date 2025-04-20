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

ll INF = LLONG_MAX / 3;

ll n, q;
ll grid[101][101];
ll dp[101][101][101];

void floyd() {
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (grid[i][k] != INF && grid[k][j] != INF) {
                    // if there is a path from i to k and from k to j, then we can find a path from i to j through k
                    // we can find the minimum cost of the path from i to j through k by taking the minimum of the current cost and the cost of the path from i to k and the cost of the path from k to j
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll x; cin >> x;
            if (i == j) grid[i][j] = 0;
            else if (x == 0) grid[i][j] = INF;
            else grid[i][j] = x;
        }
    }
    floyd();
    // for (ll i = 0; i < n; ++i) {
    //     for (ll j = 0; j < n; ++j) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    for (ll i = 0; i < n; ++i) { 
        for (ll j = 0; j < n; ++j) {
            dp[1][i][j] = grid[i][j];
        }
    }
    for (ll k = 2; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                dp[k][i][j] = INF;
                for (ll p = 0; p < n; ++p) {
                    if (dp[k-1][i][p] != INF && dp[1][p][j] != INF) {
                        // to find the optimal path from i to j in k days, we can use an optimal path from i to p in k - 1 days and then use an optimal path from p to j in one day
                        ll current_max_daily_cost = max(dp[k-1][i][p], dp[1][p][j]);
                        dp[k][i][j] = min(dp[k][i][j], current_max_daily_cost);
                    }
                }
            }
        }
    }
    cin >> q;
    for (ll _ = 0; _ < q; ++_) {
        ll s, t, d; cin >> s >> t >> d;
        s--; t--;
        if (dp[d][s][t] == INF) {
            cout << "0\n";
        } else {
            cout << dp[d][s][t] << "\n";
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
