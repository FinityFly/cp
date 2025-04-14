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

ll r, c, v=0;
char grid[320][320];
bool vis[320][320];
ll directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void traverse(ll a, ll b) {
    if (grid[a][b] == 'S') {
        v += 1;
    } else if (grid[a][b] == 'M') {
        v += 5;
    } else if (grid[a][b] == 'L') {
        v += 10;
    }
    for (int i = 0; i < 4; ++i) {
        ll newx = a + directions[i][0], newy = b + directions[i][1];
        if (vis[newx][newy]) continue;
        if (newx < 0 || newx >= r) continue;
        else if (newy < 0 || newy >= c) continue;
        else if (grid[newx][newy] == '*') continue;
        vis[newx][newy] = 1;
        traverse(newx, newy);
    }
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    ll a, b; cin >> a >> b;
    vis[a][b] = 1;
    traverse(a, b);
    cout << v << "\n";
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
