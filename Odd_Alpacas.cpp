#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

map<int, vector<pair<int, int>>> adj;
pair<int, int> lengths;

void bfs(int a) {
    queue<int> q;
    vector<bool> v;
    fill(v.begin(), v.end(), 0);
    q.push(a);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (int i = 0; i < adj.size(); ++i) {
            if (!v[a]) {
                v[a] = true;
                q.push(a);
            }
        }
        cout << a << "  ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    return 0;
}