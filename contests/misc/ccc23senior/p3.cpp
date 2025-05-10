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

ll n, m, r, c, x=-1, y=-1;
ll grid[2001][2001];

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
    if (n == 2 && m == 2) {
        if (r == 0 && c == 2) {
            cout << "ab\nab\n";
            return;
        } else if (r == 2 && c == 0) {
            cout << "aa\nbb\n";
            return;
        }
    }
    if (r == 0 && c > 0) {
        FOR (i, 0, m-c) {
            ll lcnt = 1;
            FOR (j, 0, n) {
                grid[j][i] = lcnt;
                lcnt++;
                if (lcnt > 26) lcnt=1;
            }
        }
        printGrid();
        return;
    } else if (r > 0 && c == 0) {
        FOR (i, 0, n-r) {
            ll lcnt = 1;
            FOR (j, 0, m) {
                grid[i][j] = lcnt;
                lcnt++;
                if (lcnt > 26) lcnt=1;
            }
        }
        printGrid();
        return;
    }
    if ((n == r && m != c) || (n != r && m == c)) {
        cout << "IMPOSSIBLE\n";
        return;
    } else if (n == 2 && m == 2 && ((r == 1 && c == 2) || (r == 2 && c == 1))) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    ll temp = 1;
    FOR (i, 0, max(n, m)) {
        if (r == n && c == m) break;
        if (n > r) {
            y++;
            r++;
        }
        if (m > c) {
            x++;
            c++;
        }
        grid[min(y, n-1)][min(x, m-1)] = temp;
        if (n%2 == 1 && y == n/2) {
            FOR (j, 0, n/2) grid[j][x] = temp;
        }
        if (m%2 == 1 && x == m/2) {
            FOR (j, 0, m/2) grid[y][j] = temp;
        }
        temp++;
        if (temp == 26) temp = 1;
    }
    printGrid();
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