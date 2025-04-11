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
    cin >> n;
    vpll grid;
    ll ind[n], p=0;
    FOR (i, 0, n) {
        char c; cin >> c;
        if (c == '>') {
            if (grid.empty()) {
                grid.push_back({0, 1});
                p++;
            } else if (grid[grid.size()-1].first == 0) {
                grid[grid.size()-1].second += 1;
            } else {
                grid.push_back({0, 1});
                p++;
            }
        } else {
            if (grid.empty()) {
                grid.push_back({1, 1});
                p++;
            } else if (grid[grid.size()-1].first == 1) {
                grid[grid.size()-1].second += 1;
            } else {
                grid.push_back({1, 1});
                p++;
            }
        }
        ind[i] = p;
    }
    FOR (i, 0, grid.size()) {
        cout << grid[i].first << " " << grid[i].second << "\n";
    }
    cout << "\n";
    FOR (i, 0, n) {
        ll pos = ind[i], cnt = 0;
        vpll tempgrid(grid.begin(), grid.end());
        while (pos >= 0 && pos < tempgrid.size()) {
            cnt += tempgrid[pos].second;
            if (tempgrid[pos].first == 1) {
                tempgrid[pos].first = 0;
                pos -= 1;
            } else {
                tempgrid[pos].first = 1;
                pos += 1;
            }
        }
        cout << cnt << " ";
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
