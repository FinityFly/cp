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
int c1[26], c2[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            ++c1[(int) s[i]-65];
        }
    }
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            ++c2[(int) s[i]-65];
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (c1[i] != c2[i]) {
            cout << "Is not an anagram.\n";
            return 0;
        }
    }
    cout << "Is an anagram.\n";
    return 0;
}