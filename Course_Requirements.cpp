#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
int n;
int ind[200001];
vector<int> courses[200001];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ind[i];
        for (int j = 0; j < ind[i]; ++j) {
            int b;
            cin >> b;
            courses[b-1].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ind[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cout << a+1 << " ";
        for (int i = 0; i < courses[a].size(); ++i) {
            --ind[courses[a][i]];
            if (ind[courses[a][i]] == 0)
                q.push(courses[a][i]);
        }
    }
    cout << "\n";
    return 0;
}