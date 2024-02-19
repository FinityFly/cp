#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, ans=1e9;
int c[1000001];
vector<int> adj[1000001];
vector<pii> dis1[1000001], disn[1000001];

void bfs(int a, vector<pii> d[]) {
    int dis[n+1];
    bool vis[n+1];
    fill(dis, dis+n+1, 0);
    fill(vis, vis+n+1, false);
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int color = c[cur];
        if (d[color].size() < 2) {
            d[color].push_back({cur, dis[cur]});
        }
        for (int next : adj[cur]) {
            if (!vis[next]) {
                q.push(next);
                vis[next] = true;
                dis[next] = dis[cur] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, dis1);
    bfs(n, disn);
    for (int i = 1; i <= n; ++i) {
        for (pii u: dis1[i]) {
            for (pii v : disn[i]) {
                if (u.first != v.first) {
                    ans = min(ans, u.second + v.second);
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
    return 0;
}