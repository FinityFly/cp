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

ll n, m;
pll start, finish;
ll grid[1001][1001], parent[1001][1001];
bool vis[1001][1001];

void solve() {
    cin >> n >> m;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            char c; cin >> c;
            if (c == '#') grid[i][j] = 0;
            else if (c == '.') grid[i][j] = 1;
            else if (c == 'A') {
                grid[i][j] = 1;
                start = {i, j};
            } else if (c == 'B'){
                grid[i][j] = 1;
                finish = {i, j};
            }
        }
    }
    queue<pll> q;
    memset(parent, -1, sizeof(parent));
    memset(vis, 0, sizeof(vis));
    q.push(start);
    vis[start.first][start.second] = true;
    bool found = false;
    ll moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    char dir[4] = {'U', 'D', 'L', 'R'};
    while (!q.empty()) {
        pll u = q.front(); q.pop();
        ll x = u.first, y = u.second;
        if (x == finish.first && y == finish.second) {
            cout << "YES" << "\n";
            string path = "";
            while (parent[x][y] != -1) {
                path += dir[parent[x][y]];
                ll tx = x - moves[parent[x][y]][0], ty = y - moves[parent[x][y]][1];
                x = tx, y = ty;
            }
            reverse(all(path));
            cout << path.size() << "\n";
            cout << path << "\n";
            found = true;
            break;
        }
        FOR (i, 0, 4) {
            ll nx = x + moves[i][0], ny = y + moves[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                parent[nx][ny] = i;
                q.push({nx, ny});
            }
        }
    }
    if (!found) cout << "NO" << "\n";
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
