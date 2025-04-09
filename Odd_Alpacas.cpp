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

ll n, ans = INT_MAX;
vpll adj[2001];
bool vis[2001];
ll parity[2001];

void dfs1(ll u, vpll &cnt) {
    TRAV (v, adj[u]) {
        if (!vis[v.first]) {
            vis[v.first] = true;
            parity[v.first] = (parity[u] + v.second) % 2;
            dfs1(v.first, cnt);
            if (v.second % 2 == 1) {
                ll tmp = cnt[v.first].first;
                cnt[u].first += cnt[v.first].second;
                cnt[u].second += tmp + 1;
            } else {
                cnt[u].first += cnt[v.first].first + 1;
                cnt[u].second += cnt[v.first].second;
            }
        }
    }
}

void dfs2(ll u, ll even, ll odd, vpll cnt) {
    cout << "u: " << u << " even: " << even << " odd: " << odd << "\n";
    TRAV (v, adj[u]) {
        if (!vis[v.first]) {
            vis[v.first] = true;
            dfs2(v.first, even + ((parity[u] + v.second) % 2 == 0), odd + ((parity[u] + v.second) % 2 == 1), cnt);
            // no flip
            ll oddEdges = (odd + cnt[u].second), evenEdges = (even + cnt[u].first);
            ll oddTotal = oddEdges * evenEdges;
            ll evenTotal = (n * (n - 1) / 2) - oddTotal;
            cout << "oddEdges: " << oddEdges << " evenEdges: " << evenEdges << "\n";
            cout << "oddTotal: " << oddTotal << " evenTotal: " << evenTotal << "\n";
            ll noflip = abs(oddTotal - evenTotal);

            oddEdges = (odd + cnt[u].first); evenEdges = (even + cnt[u].second);
            oddTotal = oddEdges * evenEdges;
            evenTotal = (n * (n - 1) / 2) - oddTotal;
            cout << "oddEdges: " << oddEdges << " evenEdges: " << evenEdges << "\n";
            cout << "oddTotal: " << oddTotal << " evenTotal: " << evenTotal << "\n";
            ll flip = abs(oddTotal - evenTotal);
            cout << "noflip: " << noflip << " flip: " << flip << "\n\n";
            ans = min(ans, min(noflip, flip));
        }
    }
}

void solve() {
    cin >> n;
    FOR (i, 0, n-1) {
        ll u, v, w;
        cin >> u >> v >> w;
        if (w % 2 == 0) w = 0;
        else w = 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vpll cnt(2000); // counts of odd and even nodes in each node's subtree, coming from the root of 1
    fill(parity, parity + 2001, 0);
    fill(vis, vis + 2001, false);
    vis[1] = true;
    parity[1] = 0;
    dfs1(1, cnt);
    cout << "parity:\n";
    FOR (i, 1, n+1) {
        cout << parity[i] << " ";
    }
    cout << "\n";
    cout << "cnt:\n";
    FOR (i, 1, n+1) {
        cout << cnt[i].first << " " << cnt[i].second << "\n";
    }
    cout << "\n";
    fill(vis, vis + 2001, false);
    vis[1] = true;
    dfs2(1, 1, 0, cnt);
    cout << ans << "\n";
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
