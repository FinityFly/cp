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

ll h, w;
char grid[1001][1001];
ll dist[1001][1001];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    cin >> h >> w;
    queue<pll> q; // single multi source BFS
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 0;
            } else {
                dist[i][j] = LLONG_MAX;
            }
        }
    }
    while (!q.empty()) {
        pll u = q.front(); q.pop();
        ll ux = u.first, uy = u.second;
        for (ll i = 0; i < 4; ++i) {
            ll vx = ux + dx[i];
            ll vy = uy + dy[i];
            if (vx < 0 || vx >= h || vy < 0 || vy >= w) continue;
            if (grid[vx][vy] == '#' || grid[vx][vy] == 'E') continue;
            if (dist[vx][vy] > dist[ux][uy] + 1) {
                dist[vx][vy] = dist[ux][uy] + 1;
                if (i == 0) grid[vx][vy] = '^';
                else if (i == 1) grid[vx][vy] = '<';
                else if (i == 2) grid[vx][vy] = 'v';
                else if (i == 3) grid[vx][vy] = '>';
                q.push({vx, vy});
            }
        }
    }
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
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
}
