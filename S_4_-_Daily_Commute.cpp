#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, w, d;
map<int, vector<int>> adj;
bool visited[200001];
int dist[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> d;
    for (int i = 0; i < w; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto i : adj[curr]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[curr]+1;
            }
        }
    }
    multiset<int> options;
    for (int pre = 0; pre < n; ++pre) {
        if (visited[s[pre]]) {
            options.insert(pre + dist[s[pre]]);
        }
    }
    while (d--) {
        int a, b;
        cin >> a >> b;
        int cura = a-1+dist[s[a-1]];
        int curb = b-1+dist[s[b-1]];
        int newa = b-1+dist[s[a-1]];
        int newb = a-1+dist[s[b-1]];
        if (visited[s[a-1]]) {
            options.erase(options.find(cura));
            options.insert(newa);
        }
        if (visited[s[b-1]]) {
            options.erase(options.find(curb));
            options.insert(newb);
        }
        swap(s[a-1], s[b-1]);
        cout << *options.begin() << "\n";
    }
    return 0;
}