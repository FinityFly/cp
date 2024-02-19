#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll> >;
using vpll = vector<pair<ll, ll> >;

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

#define MM 100001
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

ll n;
ll h[5001], out[5001];
ll dp[5001][5001];
bool dp_solved[5001][5001];

void solve() {
    cin >> n;
    FOR (i, 0, n) {
        cin >> h[i];
    }
    out[0] = 0;
    RFOR (width, n, 1) {
        ll m=INT_MAX;
        // cout << width << ": " << (width/2)-(width%2==0) << " - " << n-(width/2) << "\n";
        FOR (i, (width/2)-(width%2==0), n-(width/2)) {
            ll diff=0;
            ll log[n];
            fill(log, log+n, 0);
            RFOR (k, (width/2), 0) {
                if (dp_solved[i-k+(width%2==0)][i+k]) {
                    diff += min(m, dp[i-k+(width%2==0)][i+k]);
                    break;
                }
                diff += abs(h[i-k+(width%2==0)]-h[i+k]);
                log[(width/2)-k+1] = log[(width/2)-k] + abs(h[i-k+(width%2==0)]-h[i+k]);
            }
            RFOR (k, (width/2)-1, 0) {
                dp[i-k+(width%2==0)][i+k] = diff-log[(width/2)-k];
                dp_solved[i-k+(width%2==0)][i+k] = true;
            }
            m = min(m, diff);
        }
        out[width-1] = m;
    }
    FOR (i, 0, n) {
        cout << out[i] << " ";
    }
    cout << "\n";
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