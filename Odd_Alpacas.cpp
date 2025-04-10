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

int n, evenCnt = 0, oddCnt = 0;
ll ans = LONG_LONG_MAX;
vector<pair<int, int>> adj[200001];
bool vis[200001];
int parity[200001];
int cnt[200001][2]; // counts of odd and even nodes in each node's subtree, coming from the root of 1

pair<int, int> dfs1(int u) {
    int evenNodes = 0, oddNodes = 0;
    if (parity[u] == 0) evenNodes = 1;
    else oddNodes = 1;
    TRAV (x, adj[u]) {
        int v = x.first, w = x.second;
        if (!vis[v]) {
            vis[v] = true;
            parity[v] = (parity[u] + w) % 2;
            if (parity[v] == 0) evenCnt++;
            else oddCnt++;
            pair<int, int> sub = dfs1(v);
            evenNodes += sub.first;
            oddNodes += sub.second;
        }
    }
    cnt[u][0] = evenNodes;
    cnt[u][1] = oddNodes;
    return {evenNodes, oddNodes};
}

void dfs2(int u) {
    TRAV (v, adj[u]) {
        if (!vis[v.first]) {
            vis[v.first] = true;
            dfs2(v.first);

            int oddNodes = oddCnt - cnt[v.first][1] + cnt[v.first][0];
            int evenNodes = evenCnt - cnt[v.first][0] + cnt[v.first][1];

            ll oddTotal = oddNodes * 1LL * evenNodes;
            ll evenTotal = (n * 1LL * (n - 1) / 2) - oddTotal;
            ll flip = abs(oddTotal - evenTotal);
            ans = min(ans, flip);
        }
    }
}

void solve() {
    cin >> n;
    FOR (i, 0, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w % 2 == 0) w = 0;
        else w = 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill(parity, parity + 200001, 0);
    fill(vis, vis + 200001, false);

    vis[1] = true;
    parity[1] = 0;
    evenCnt = 1;

    dfs1(1);

    fill(vis, vis + 200001, false);

    vis[1] = true;

    dfs2(1);

    ll oddTotal = evenCnt * 1LL * oddCnt;
    ll evenTotal = (n * 1LL * (n - 1) / 2) - oddTotal;
    ll noflip = abs(oddTotal - evenTotal);
    cout << min(ans, noflip) << "\n";
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
