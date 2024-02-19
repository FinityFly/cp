#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
bool isCyclic = false;
int adj[1001][1001], vis[1001];

void dfs(int u) {
    vis[u] = 1;
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] == 1) {
            if (vis[v] == 1) {
                isCyclic = true;
            } else if (vis[v] == 0) {
                dfs(v);
            }
        }
    }
    vis[u] = 2;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    if (isCyclic) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}