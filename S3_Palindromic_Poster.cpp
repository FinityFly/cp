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

ll n, m, r, c, ar, ac, x=-1, y=-1;
ll grid[2001][2001];
ll junk[3] = {1, 2, 3};

void printGrid() {
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            if (grid[i][j] > 0) cout << (char)('a'+grid[i][j]);
            else cout << "a";
        }
        cout << "\n";
    }
}

void solve() {
    cin >> n >> m >> r >> c;
    ar=r; ac=c;
    if (r == n) {
        FOR (i, 0, n-1) {
            FOR (j, 0, m) {
                grid[i][j] = 0;
            }
        }
        FOR (i, 0, m) {
            grid[n-1][i] = 1;
        }
        FOR (i, 0, m) {
            if (i >= m-i-1) break;
            if (c >= 2) {
                grid[n-1][i] = 0;
                grid[n-1][m-i-1] = 0;
                c -= 2;
            }
        }
        if (c>0) {
            grid[n-1][m/2] = 0;
        }
    } else if (c == m) {
        FOR (i, 0, n) {
            FOR (j, 0, m-1) {
                grid[i][j] = 0;
            }
        }
        FOR (i, 0, n) {
            grid[i][m-1] = 1;
        }
        FOR (i, 0, n) {
            if (i >= n-i-1) break;
            if (r >= 2) {
                grid[i][m-1] = 0;
                grid[n-i-1][m-1] = 0;
                r -= 2;
            }
        }
        if (r>0) {
            grid[n/2][m-1] = 0;
        }
    } else {
        FOR (i, 0, n) {
            FOR (j, 0, m) {
                grid[i][j] = junk[(i+j)%3];
            }
        }
        FOR (i, 0, r) {
            FOR (j, 0, m) {
                grid[i][j] = 0;
            }
        }
        FOR (i, 0, c) {
            FOR (j, 0, n) {
                grid[j][i] = 0;
            }
        }
    }
    ll rcnt=0, ccnt=0;
    FOR (i, 0, n) {
        bool p=1;
        FOR (j, 0, m) {
            if (grid[i][j] != grid[i][m-j-1]) p=0;
        }
        if (p) ++rcnt;
    }
    FOR (j, 0, m) {
        bool p=1;
        FOR (i, 0, n) {
            if (grid[i][j] != grid[n-i-1][j]) p=0;
        }
        if (p) ++ccnt;
    }
    if (rcnt != ar || ccnt != ac) {
        cout << "IMPOSSIBLE\n";
    } else {
        printGrid();
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