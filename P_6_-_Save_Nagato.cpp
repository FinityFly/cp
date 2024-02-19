#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, far;
int dis1[500001], dis2[500001];
vector<int> adj[500001];

void bfs(int a, int dis[]) {
    bool v[500001];
    fill(v, v+500001, false);
    queue<int> q;
    q.push(a);
    v[a] = true;
    dis[a] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        far = cur;
        for (auto next: adj[cur]) {
            if (!v[next]) {
                v[next] = true;
                dis[next] = dis[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, dis1);
    bfs(far, dis1);
    bfs(far, dis2);
    for (int i = 1; i <= n; ++i) {
        cout << max(dis1[i], dis2[i])+1 << "\n";
    }
    return 0;
}