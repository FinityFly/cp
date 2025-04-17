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

int r, c;
char grid[51][51];
int t[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    cin >> r >> c;
    int x, y;
    queue<pair<int, int>> flood;
    memset(t, -1, sizeof(t));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                x = i;
                y = j;
            } else if (grid[i][j] == '*') {
                flood.push({i, j});
                t[i][j] = 0;
            }
        }
    }
    while (!flood.empty()) {
        auto [x, y] = flood.front(); flood.pop();
        for (auto [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (grid[nx][ny] == 'D' || grid[nx][ny] == 'S') continue;
            if (grid[nx][ny] == '*' || grid[nx][ny] == 'X') continue;
            if (t[nx][ny] != -1) continue;
            t[nx][ny] = t[x][y] + 1;
            flood.push({nx, ny});
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    bool vis[51][51] = {false};
    vis[x][y] = true;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        auto [x, y] = cur.second;
        int time = cur.first;
        // cout << x << " " << y << ": " << time << "\n";
        for (auto [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis[nx][ny]) continue;
            if (grid[nx][ny] == 'D') {
                cout << time+1 << "\n";
                return;
            }
            if (grid[nx][ny] == 'X') continue;
            if (t[nx][ny] != -1 && t[nx][ny] <= time+1) continue;
            q.push({time+1, {nx, ny}});
            vis[nx][ny] = true;
        }
    }
    cout << "KAKTUS\n";
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
