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
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        set<string> seq;
        bool isUnique = true;
        for (int j = 0; j < n-i+1; ++j) {
            if (seq.find(s.substr(j, i)) != seq.end()) {
                isUnique = false;
                break;
            } else {
                seq.insert(s.substr(j, i));
            }
        }
        if (isUnique) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}