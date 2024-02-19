#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/
int n, m;
vector<pair<int, int>> adj[100000];

int minWeight(int weight[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && weight[i] < min) {
            min = weight[i];
            min_index = i;
        }
    }
    cout << "\nWEIGHT: \n";
    for (int i = 0; i <= n; ++i) {
        cout << weight[i] << " ";
    }
    cout << "\nVISITED: \n";
    for (int i = 0; i <= n; ++i) {
        if (visited[i]) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    cout << "\n";
    cout << "min index: " << min_index << "\n";
    return min_index;
}

void prim(int a) {
    int mst[n+1];
    int weight[n+1];
    bool visited[n+1];
    fill(weight, weight+n+1, INT_MAX);
    fill(visited, visited+n+1, 0);
    weight[a] = 0;
    mst[a] = -1;
    for (int i = 0; i < n-1; ++i) {
        int u = minWeight(weight, visited);
        visited[u] = 1;
        for (int v = 1; v <= n; ++v) {
            cout << "v: " << v << "\n";
            cout << "adj[u][v].second: " << adj[u][v].second << "\n";
            cout << "weight[v]: " << weight[v] << "\n";
            if (adj[u][v-1].second && visited[v] == false && (adj[u][v-1].second < weight[v])) {
                cout << "yes\n";
                mst[v] = u;
                weight[v] = adj[u][v-1].second;
            }
        }
    }
    // cout << "MST: \n";
    // for (int i = 0; i <= n; ++i) {
    //     cout << mst[i] << " ";
    // }
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i+1});
        adj[b].push_back({a, i+1});
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << i << " - " << adj[i][j].first << " | " << adj[i][j].second << "\n";
        }
    }
    cout << "\n\n";
    prim(1);
    return 0;
}
