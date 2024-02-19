#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Adjacency List:
-Vector implementation has cache friendliness

Format: 
-Unweighted
    -neighbours<ids> adj[node id];
    -[[node 0's neighbours], [node 1's neighbours]]
-Weighted
    -neighbours<neighbour<ids, weights>> adj[node id];
*/

class Graph {
    public:
    vector<int>* adj; // Unweighted
    // vector<pair<int, int>>* adjWeighted; // Weighted
    int nodeCount;

    Graph(int nodeCount) {
        this->nodeCount = nodeCount;
        adj = new vector<int>[nodeCount];
        for (int i = 0; i < nodeCount; ++i) {
            adj[i] = vector<int>();
        }
        // adjWeighted = new vector<pair<int, int>>[nodeCount];
        // for (int i = 0; i < nodeCount; ++i) {
        //     adjWeighted[i] = vector<pair<int, int>>();
        // }
    }
    
    // Unweighted
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed
    }
    // Weighted
    // void addEdge(int u, int v, int w) {
    //     adjWeighted[u].push_back(make_pair(v, w));
    //     adjWeighted[v].push_back(make_pair(u, w)); // remove this line for directed
    // }

    // Print adjacency list
    void toString() {
        for (int i = 0; i < nodeCount; ++i) {
            cout << i << ":";
            for (auto j : adj[i]) {
                cout << " " << j;
            }
            cout << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    Graph graph = Graph(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    graph.toString();

    return 0;
}