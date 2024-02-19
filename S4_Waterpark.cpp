#include <bits/stdc++.h>
using namespace std;

int n, dp[10000];
vector<int> adj[10000];

int dfs(int node) {
    if (dp[node] != 0) {
        return dp[node];
    }
    if (node == n) {
        return 1;
    }
    for (int i = 0; i < adj[node].size(); ++i) {
        dp[node] += dfs(adj[node][i]);
    }
    return dp[node];
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        } else {
            adj[a].push_back(b);
        }
    }
    memset(dp, 0, sizeof(dp));
    cout << dfs(1) << "\n";
    return 0;
}