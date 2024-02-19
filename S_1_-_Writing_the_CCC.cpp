#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int t, n;
string s[100001];
unordered_map<string, vector<int>> p;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s[i];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        p[a].push_back(i+1);
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < p[s[i]].size(); ++j) {
            cout << p[s[i]][j] << "\n";
        }
    }
    return 0;
}