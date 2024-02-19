#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
vector<string> order;
map<string, int> ind;
map<string, vector<string>> adj;

vector<string> hasZero() {
    vector<string> batch;
    for (auto i : ind)
        if (i.second == 0) batch.push_back(i.first);
    return batch;
}

int getIndex(string k) {
    int in = 1;
    for (auto i : order) {
        if (i == k)
            return in;
        ++in;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (find(order.begin(), order.end(), a) == order.end())
            order.push_back(a);
        if (find(order.begin(), order.end(), b) == order.end())
            order.push_back(b);
        adj[b].push_back(a);
        ind[b] = max(ind[b], 0);
        ind[a]++;
    }
    vector<string> batch = hasZero();
    while (batch.size() > 0) {
        sort(batch.begin(), batch.end(), [](string a, string b) {
            if (getIndex(a) < getIndex(b)) {
                return true;
            }
            return false;
        });
        string name = batch[0];
        cout << name << "\n";
        for (int i = 0; i < adj[name].size(); ++i) {
            ind[adj[name][i]]--;
        }
        ind[name] = -1;
        batch = hasZero();
    }
    return 0;
}