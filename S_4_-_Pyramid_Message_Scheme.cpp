#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int l, n, m=-1, output=-1;
map<string, vector<string>> adj;
map<string, int> dis;
string input[101];

int getDepth(string a) {
    map<string, bool> v;
    queue<string> q;
    q.push(a);
    v[a] = true;
    dis[a] = 0;
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        for (auto next: adj[cur]) {
            if (v.find(next) == v.end()) {
                dis[next] = dis[cur] + 1;
                m = max(m, dis[next]);
                v[next] = true;
                q.push(next);
            }
        }
    }
    return m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l;
    for (int t = 0; t < l; ++t) {
        adj.clear();
        dis.clear();
        m = -1;
        output = -1;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        adj[input[n-1]].push_back(input[0]);
        for (int i = 0; i < n-1; ++i) {
            if (adj.find(input[i+1]) == adj.end())
                adj[input[i]].push_back(input[i+1]);
        }
        for (auto i : adj) {
            output = max(output, getDepth(i.first));
        }
        cout << n*10-output*20 << "\n";
    }
    return 0;
}