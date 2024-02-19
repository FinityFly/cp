#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;

void makeSet(int n) {
    for (int i = 1; i < n+1; ++i) {
        parent[i] = i;
    }
}

int find(int node) {
    while(parent[node] != node) {
        node = parent[node];
    }
    return node;
}

void merge(int node_1, int node_2) {
    parent[node_2] = node_1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    makeSet(n);
    for (int i = 0; i < m; ++i) {
        cout << "hi\n";
        string x;
        int a, b;
        cin >> x >> a >> b;
        if (x == "union") {
            merge(a, b);
        } else {
            if (find(a) == find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}