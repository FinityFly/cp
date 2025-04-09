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

ll n;

void solve() {
    ll lowest=INT_MAX, lowest_cnt=0;
    cin >> n;
    set<ll> arr;
    FOR (i, 0, n) {
        ll a; cin >> a;
        if (a < lowest) {
            lowest = a;
            lowest_cnt = 1;
        } else if (a == lowest) {
            lowest_cnt++;
        }
        arr.insert(a);
    }
    if (lowest_cnt == 1) {
        cout << "YES\n";
        return;
    } else if (lowest_cnt == n) {
        cout << "NO\n";
        return;
    } else {
        // for (auto it = arr.begin(); it != arr.end(); ++it) {
        //     for (auto jt = next(it); jt != arr.end(); ++jt) {
        //         if (*it % *jt < lowest && *it % *jt != 0) {
        //             // cout << *it << " " << *jt << "\n";
        //             cout << "YES\n";
        //             return;
        //         }
        //     }
        // }

        TRAV(i, arr) {
            auto it = lower_bound(arr.begin(), arr.end(), i / 2);
            // cout << i << " " << *it << "\n";
            if (it != arr.begin()) {
                ll c1 = i % *prev(it);
                // cout << "c1: " << c1 << "\n";
                if (c1 != 0 && c1 < lowest) {
                    cout << "YES\n";
                    return;
                }
            }
            ll c2 = i % *it;
            if (c2 != 0 && c2 < lowest) {
                cout << "YES\n";
                return;
            }
            // cout << "c2: " << c2 << "\n";
        }
    }
    cout << "NO\n";
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
