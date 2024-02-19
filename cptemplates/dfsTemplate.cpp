#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
For directed graph
*/
map<int, bool> visited;
map<int, vector<int>> adj;

void dfs(int v) {
  visited[v] = true;
  cout << v << " ";
  list<int>::iterator i;
  for (int i = adj[v].begin(); i != adjList.end(); ++i) {
      if (!visited[*i]) {
          dfs(*i);
      }
  }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    return 0;
}