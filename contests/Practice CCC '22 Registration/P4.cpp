#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

vector<int> parent;
vector<int> ranks;
vector<vector<int>> edges;

void makeSet(vector<vector<int>> &set) {
    for (int i = 0; i < set.size(); ++i) {
        parent[i] = i;
        ranks[i] = set[i][0];
    }
}

int find(int node) {
    while(parent[node] != node) {
        node = parent[node];
    }
    return node;
}

void merge(int node_1, int node_2) {
    if (ranks[node_1] < ranks[node_2]) {
        swap(node_1, node_2);
    }
    parent[node_2] = node_1;
    ranks[node_1] += ranks[node_2];
}

bool edgeExists(int a, int b) {
    pair<int, int> edge;
    if (a < b) {
        edge = make_pair(a, b);
    } else {
        edge = make_pair(b, a);
    }
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i][1] == edge.first && edges[i][2] == edge.second) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        int a[e+1], b[e];
        for (int j = 0; j < e; ++j) {
            cin >> a[j];
        }
        a[e] = a[0];
        cout << "\n";
        for (int j = 0; j < e; ++j) {
            cin >> b[j];
        }
        for (int j = 0; j < e; ++j) {
            if (!edgeExists(a[j], a[j+1])) {
                if (a[j] < a[j+1]) {
                    edges.push_back({b[j], a[j], a[j+1]});
                } else {
                    edges.push_back({b[j], a[j+1], a[j]});
                }
            }
        }
    }
    // for (int i = 0; i < edges.size(); ++i) {
    //     cout << edges[i][0] << ": " << edges[i][1] << ' ' << edges[i][2] << "\n";
    // }
    parent.resize(edges.size() + 1), ranks.resize(edges.size() + 1);
    makeSet(edges);

    // SORT THE SETS

    for (int i = 0; i < edges.size()+1; ++i) {
        cout << parent[i] << ' ';
    }
    cout << "\n";
    for (int i = 0; i < edges.size()+1; ++i) {
        cout << ranks[i] << ' ';
    }
    cout << "\n\n";
    int ans = 0;
    for (vector<int> edge : edges) {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        if (find(x) != find(y)) {
            merge(x, y);
            ans += w;
        }
    }
    cout << ans << "\n";
    return 0;
}