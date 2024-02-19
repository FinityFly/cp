#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
int a[500][500];
vector<vector<int>> adj;
bool vis[500][500];

void bfs(int a, int n) {
    queue<int> q;
    vector<bool> v(n);
    q.push(a);
    fill(v.begin(), v.end(), false);
    v[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!v[adj[cur][i]]) {
                v[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
        }
        cout << cur << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == i)
                break;
            adj[i].push_back(a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i){
        bfs(i, vis[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; i <= n; ++i) {
            int k = a[i][j];
            if (vis[i][k] && vis[k][i]) {
                cout << k << "\n";
                break;
            }
        }
    }
    return 0;
}