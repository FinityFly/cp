#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Adjacency Matrix:
-Convenient for weighted graph
-Consumes more space
*/

// Adjacency Matrix
class Graph {
    public:
    int** adj;
    int nodeCount;

    Graph(int nodeCount) {
        this->nodeCount = nodeCount;
        adj = new int*[nodeCount];
        for (int i = 0; i < nodeCount; ++i) {
            adj[i] = new int[nodeCount];
            for (int j = 0; j < nodeCount; ++j) {
                adj[i][j] = 0;
            }
        }
    }

    // Unweighted
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed
    }
    // Weighted
    // void addEdge(int u, int v, int w) {
    //     adj[u][v] = w;
    //     adj[v][u] = w; // remove this line for directed
    // }

    // Print adjacency matrix
    void toString() {
        for (int i = 0; i < nodeCount; i++) {
            cout << i << ": ";
            for (int j = 0; j < nodeCount; j++) {
                cout << adj[i][j] << " ";
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