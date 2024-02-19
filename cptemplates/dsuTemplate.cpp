#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
NOTE : This is a template for a disjoint set considering weights.
Unweighted sets can do without vector<int> ranks and its instances,
as well as reducing set into a 1D array

DSU can be used for Prim's, Kruskal's, and Kosaraju's. 
Prim and Kruskal: minimum spanning tree
    -Prim better in dense graphs
    -Kruskal's better in sparse graphs
Kosaraju: strongly connected components
*/

vector<int> parent;
vector<int> ranks;

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

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    return 0;
}