#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, a, b;
map<int, vector<int>> adj;
int visited[10000];

int dfs(int v, int u, int d) {
    visited[v] = d;
    if (v == u) return d;
    bool isCycle = true;
    for (auto i : adj[v]) {
        if (visited[i] == -1) {
            dfs(i, u, d+1);
            isCycle = false;
        }
    }
    if (isCycle) return -1;
    else return visited[u]-1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cout << x << " " << y << "\n";
        adj[x].push_back(y);
    }
    while (cin >> a >> b) {
        cout << a << " " << b << "\n";
        fill(visited, visited+n, -1);
        if (a != 0 && b != 0) {
            int dist = dfs(a, b, 0);
            // if (dist == -1)
            //     cout << "No\n";
            // else
            //     cout << "Yes " << dist << "\n";
        } else break;
    }
    return 0;
}