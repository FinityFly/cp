#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
unordered_map<string, string> pairs;
string temp[31];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        if (pairs.find(a) == pairs.end() && pairs.find(temp[i]) == pairs.end()) {
            pairs[a] = temp[i];
            pairs[temp[i]] = a;
        } else if ((pairs[a] != temp[i] && pairs[temp[i]] != a) || a == temp[i]) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "good\n";
    return 0;
}