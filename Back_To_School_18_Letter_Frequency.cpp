#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
string s;
int q;
int psa[26][1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            psa[s[i]-97][i+1] = psa[s[i]-97][i] + 1;
            for (int j = 0; j < 26; ++j) {
                if (j != s[i]-97) {
                    psa[j][i+1] = psa[j][i];
                }
            }
        } else {
            for (int j = 0; j < 26; ++j) {
                psa[j][i+1] = psa[j][i];
            }
        }
    }
    cin >> q;
    for (int t = 0; t < q; ++t) {
        int i, j;
        char c;
        cin >> i >> j >> c;
        cout << psa[c-97][j]-psa[c-97][i-1] << "\n";
    }
    return 0;
}