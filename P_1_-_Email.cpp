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
string s, t, u;
set<string> emails;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int d = 0; d < 10; ++d) {
        cin >> n;
        emails.clear();
        int cnt=0;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            auto split = s.find('@');
            t = s.substr(0, split);
            string prefix, suffix;
            for (int j = 0; j < t.length(); ++j) {
                if (t[j] == '+') {
                    break;
                } else if (t[j] == '.') {
                    continue;
                } else {
                    prefix += (char) tolower(t[j]);
                }
            }
            u = s.substr(split, s.length()-split);
            for (int j = 0; j < u.length(); ++j) {
                suffix += (char) tolower(u[j]);
            }
            if (emails.find(prefix+suffix) == emails.end()) {
                emails.insert(prefix+suffix);
                ++cnt;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}