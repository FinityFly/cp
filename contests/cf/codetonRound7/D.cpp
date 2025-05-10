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

ll t, n, q;
ll a[100001], psa[100002];

void solve() {
    cin >> t;
    while (t--) {
        fill(a, a+100001, 0);
        fill(psa, psa+100002, 0);
        cin >> n >> q;
        FOR (i, 0, n) cin >> a[i];
        FOR (i, 1, n+1) {
            psa[i] = psa[i-1] + a[i-1];
        }
        FOR (r, 0, q) {
            ll c; cin >> c;
            if (c == 1) {
                ll s; cin >> s;
                if (s == 0) {
                    cout << "YES\n";
                    continue;
                }
                bool found = false;
                for (ll j = 0; j < n && !found; ++j) {
                    FOR (k, j+1, n+1) {
                        if (psa[k] - psa[j] == s) {
                            found = true;
                            break;
                        }
                    }
                }
                cout << (found ? "YES\n" : "NO\n");
            } else if (c == 2) {
                ll ind, v; cin >> ind >> v;
                if (a[ind-1] == v) continue;
                else {
                    FOR (j, ind, n+1) {
                        psa[j] += v - a[ind-1];
                    }
                }
            }
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
