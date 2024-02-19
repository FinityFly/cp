#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[300001];
int dp[300001];

void dfs(int u, int cur) {
    for (int v : adj[u]) {
        if (v < cur && dp[v] == -1) {
            dp[v] = cur;
            dfs(v, cur);
        }
    }
}

int main() {
    fill(dp, dp+300001, -1);
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = n; i > 0; --i)
        dfs(i, i);
    for (int i = n; i > 0; --i) {
        if (dp[i] != -1) {
            cout << i << " " << dp[i] << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}