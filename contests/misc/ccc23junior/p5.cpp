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

#define MM 100001
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
// #define PRECISION ;
// #define FILE ;

#define SINGLE ;
// #define MULTIPLE ;
// #define GOOGLE ;

string w;
ll r, c, cnt=0;
char grid[101][101];
ll dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
ll ch1[2][2] = {{0, -1}, {-1, 0}};
ll ch2[2][2] = {{1, -1}, {-1, 1}};
vpll pos;
bool vis[101][101];

ll dfs(ll x, ll y, ll dx, ll dy, ll ind, bool hasTurned) {
    if (grid[x][y] == w[w.length()-1]) return 1;
    ll out=0;
    if (!hasTurned) {
        if (dx != 0 && dy != 0) {
            FOR (i, 0, 2) {
                if (grid[x + dx*ch2[i][0]][y + dy*ch2[i][1]] == w[ind+1] && (x + dx*ch2[i][0] >= 0 && x + dx*ch2[i][0] < r && y + dy*ch2[i][1] >= 0 && y + dy*ch2[i][1] < c)) {
                    out += dfs(x + dx*ch2[i][0], y + dy*ch2[i][1], dx*ch2[i][0], dy*ch2[i][1], ind+1, 1);
                }
            }
        } else {
            if (dx == 0) {
                if (grid[x + 1][y] == w[ind+1] && (x + 1 >= 0 && x + 1 < r && y >= 0 && y < c))
                    out += dfs(x + 1, y, 1, 0, ind+1, 1);
                if (grid[x - 1][y] == w[ind+1] && (x - 1 >= 0 && x - 1 < r && y >= 0 && y < c))
                    out += dfs(x - 1, y, -1, 0, ind+1, 1);
            } else if (dy == 0) {
                if (grid[x][y + 1] == w[ind+1] && (x >= 0 && x < r && y + 1 >= 0 && y + 1 < c))
                    out += dfs(x, y + 1, 0, 1, ind+1, 1);
                if (grid[x][y - 1] == w[ind+1] && (x >= 0 && x < r && y - 1 >= 0 && y - 1 < c))
                    out += dfs(x, y - 1, 0, -1, ind+1, 1);
            }
        }
    }
    if (grid[x + dx][y + dy] == w[ind+1] && (x + dx >= 0 && x + dx < r && y + dy >= 0 && y + dy < c)) {
        out += dfs(x + dx, y + dy, dx, dy, ind+1, hasTurned);
    }
    return out;
}

void solve() {
    cin >> w >> r >> c;
    FOR (i, 0, r) {
        FOR (j, 0, c) {
            cin >> grid[i][j];
            if (grid[i][j] == w[0]) pos.push_back({i, j});
        }
    }
    TRAV (i, pos) {
        FOR (j, 0, 8) {
            if (grid[i.first + dir[j][0]][i.second + dir[j][1]] == w[1] && (i.first + dir[j][0] >= 0 && i.first + dir[j][0] < r && i.second + dir[j][1] >= 0 && i.second + dir[j][1] < c)) {
                cnt += dfs(i.first + dir[j][0], i.second + dir[j][1], dir[j][0], dir[j][1], 1, 0);
            }
        }
    }
    cout << cnt << "\n";
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