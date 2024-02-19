#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, dia, far, rad=INT_MAX;
int dis[500001], pre[500001];
vector<pii> adj[500001];

void dfs(int cur, int parent, int d) {
    pre[cur] = parent;
    dis[cur] = d;
    if (d > dia) {
        dia = d;
        far = cur;
    }
    for (pii next : adj[cur]) {
        if (next.first != parent) {
            dfs(next.first, cur, d + next.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0, u, v, w; i < n-1; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, -1, 0);
    dia = 0;
    dfs(far, -1, 0);
    for (int i = far; i != -1; i = pre[i]) {
        rad = min(rad, max(dis[i], dia-dis[i]));
    }
    cout << dia << "\n" << rad << "\n";
    return 0;
}