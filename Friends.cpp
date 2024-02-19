#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*
20
5 1
1 2
2 3
3 4
4 5
1000 2000
2000 3000
3000 4000
4000 5000
5
*/
int n, a, b;
map<int, vector<int>> adj;
bool visited[10000];
int dist[10000];

int dfs(int v, int u, int d) {
    visited[v] = true;
    dist[v] = d;
    if (v == u) return d;
    bool isCycle = true;
    for (auto i : adj[v]) {
        if (!visited[i]) {
            dfs(i, u, d+1);
            isCycle = false;
        }
    }
    if (isCycle) return -1;
    else return dist[u]-1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    while (cin >> a >> b) {
        fill(visited, visited+10000, false);
        fill(dist, dist+10000, 0);
        if (a != 0 && b != 0) {
            int d = dfs(a, b, 0);
            if (d == -1)
                cout << "No\n";
            else
                cout << "Yes " << d << "\n";
        } else break;
    }
    return 0;
}