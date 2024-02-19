#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*
0 1
3 1
4 1
0 2
*/
int n, cnt=0, b[200001], w[200001];
char c[200001];
bool visited[200001];
map<int, vector<int>> adj;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : adj[i]) {
            if (c[j] == 'B') ++b[i];
            else ++w[i];
        }
    }
    for (int v = 0; v < n; ++v) {
        fill(visited, visited+n, false);
        visited[v] = true;
        // cout << "starting: " << v << "\n";
        for (auto i : adj[v]) {
            if (!visited[i]) {
                visited[i] = true;
                // cout << "heading: " << i << "\n";
                if (c[v] == 'B' && c[i] == 'B') {
                    cnt += b[i]-1;
                    // cout << "added: " << b[i]-1 << "\n";
                } else if (c[v] == 'W' && c[i] == 'W') {
                    cnt += w[i]-1;
                    // cout << "added: " << w[i]-1 << "\n";
                }
            }
        }
        // cout << "cnt: " << cnt << "\n\n";
    }
    cout << cnt << "\n";
    return 0;
}