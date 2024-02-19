#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m, Q, ans=0;
int dis[100001], disRoot[100001], disVert[100001];
bool vis[100001], reVis[100001], vertVis[100001];
vector<pii> adj[100001];
queue<int> q;

int dbfs(int a) {
    q.push(a);
    vis[a] = true;
    int maxE = 0, maxDis = 0, endpoint = a;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (maxE < dis[cur]) {
            maxE = dis[cur];
            endpoint = cur;
        }
        for (auto next : adj[cur]) {
            if (!vis[next.first]) {
                vis[next.first] = true;
                dis[next.first] = dis[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    q.push(endpoint);
    reVis[endpoint] = true;
    dis[endpoint] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        maxDis = max(maxDis, dis[cur]);
        for (auto next : adj[cur]) {
            if (!reVis[next.first]) {
                reVis[next.first] = true;
                dis[next.first] = dis[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    return maxDis;
}

int rbfs(int a) {
    q.push(a);
    vis[a] = true;
    int maxE=0, root=a, connectedPoints=0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ++connectedPoints;
        if (maxE < dis[cur]) {
            maxE = dis[cur];
            root = cur;
        }
        for (auto next : adj[cur]) {
            if (!vis[next.first]) {
                vis[next.first] = true;
                dis[next.first] = dis[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    int vertex = root, pin=1;
    int edges[connectedPoints+1];
    maxE = 0;
    q.push(root);
    reVis[root] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        edges[pin++] = cur;
        if (disRoot[cur] > maxE) {
            maxE = disRoot[cur];
            vertex = cur;
        }
        for (auto next : adj[cur]) {
            if (!reVis[next.first]) {
                reVis[next.first] = true;
                disRoot[next.first] = disRoot[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    q.push(vertex);
    vertVis[vertex] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto next : adj[cur]) {
            if (!vertVis[next.first]) {
                vertVis[next.first] = true;
                disVert[next.first] = disVert[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    ans = max(disRoot[edges[1]], disVert[edges[1]]);
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> Q;
    for (int i = 0, u, v, l; i < m; ++i) {
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    if (Q == 1) {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans += dbfs(i) + 1;
            }
        }
        cout << ans-1 << "\n";
    } else {

    }
    // dfs(1, -1, 0);
    // dia = 0;
    // dfs(far, -1, 0);
    // if (q == 1) {
    //     for (int i = 1; i <= n; ++i) {
    //         if (!exists[i]) ++cnt;
    //     }
    //     cout << dia + cnt << "\n";
    // } else {
    //     int rad=INT_MAX;
    //     for (int i = far; i != -1; i = pre[i]) {
    //         rad = min(rad, max(dis[i], dia-dis[i]));
    //     }
    //     cout << rad << "\n";
    // }
    return 0;
}