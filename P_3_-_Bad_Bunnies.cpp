#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, r, x, y;
int dis[200001], pre[200001];
bool vis[200001];
map<int, vector<int>> adj;
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < r; ++i) {
        int a;
        cin >> a;
        q.push(a);
        dis[a] = 0;
        vis[a] = true;
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : adj[cur]) {
            if (!vis[next]) {
                q.push(next);
                vis[next] = true;
                dis[next] = dis[cur] + 1;
            }
        }
    }
    cin >> x >> y;
    fill(vis, vis+n+1, false);
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto next : adj[cur]) {
            if (!vis[next]) {
                q.push(next);
                vis[next] = true;
                pre[next] = cur;
            }
        }
    }
    int ans = INT_MAX;
    for (int i = y; i != 0; i=pre[i]) {
        ans = min(ans, dis[i]);
    }
    cout << ans << "\n";
    return 0;
}