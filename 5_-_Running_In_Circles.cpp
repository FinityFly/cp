#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
int vis[101], dis[101], output;
map<int, vector<int>> adj;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) {
            output = dis[u] - dis[v] + 1;
        } else if (vis[v] == 0) {
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int t = 0; t < 5; ++t) {
        adj.clear();
        fill(vis, vis+101, 0);
        fill(dis, dis+101, 0);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        dfs(1);
        cout << output << "\n";
    }
    return 0;
}