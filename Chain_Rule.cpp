#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m;
vector<pii> adj[100001];
int dis[100001];
bool vis[100001];

void topSort(int u, stack<int>& s) {
    vis[u] = true;
    for (auto v : adj[u])
        if (!vis[v.first])
            topSort(v.first, s);
    s.push(u);
}

void dijk(int a) {
    stack<int> s;
    fill(vis, vis+n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            topSort(i, s);
    fill(dis, dis+n, INT_MIN);
    dis[a] = 0;
    vis[a] = true;
    s.push(a);
    while (!s.empty()) {
        int u = s.top(); s.pop();
        if (dis[u] != INT_MIN) {
            for (auto v : adj[u]) {
                if (dis[u] + v.second > dis[v.first]) {
                    dis[v.first] = dis[u] + v.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        (dis[i] == INT_MIN) ? cout << "INF " : cout << dis[i] << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b, t; i < m; ++i) {
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    int m1=-1;
    dijk(0);
    // for (int i = 0; i < n; ++i) m1 = max(m1, dis[i]);
    // for (int i = 0; i < n; ++i) cout << dis[i] << " ";
    // cout << m1 << "\n";

    return 0;
}