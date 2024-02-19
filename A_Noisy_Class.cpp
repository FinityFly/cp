#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m;
int vis[101];
bool pos=true;
vector<int> adj[10001];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) {
            pos = false;
        } else if (vis[v] == 0) {
            dfs(v);
        }
    }
    vis[u] = 2;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        dfs(i);
    if (pos) cout << "Y\n";
    else cout << "N\n";
    return 0;
}