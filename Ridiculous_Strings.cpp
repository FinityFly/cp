#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int n, m, cnt=0;
string s, t;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        bool add = false;
        for (int j = 0; j < n; ++j) {
            if (t[i] == s[j]) {
                add = true;
                ++i;
                break;
            }
        }
        if (add) ++cnt;
        else {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        
    }
    return 0;
}