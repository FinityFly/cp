#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/

string s;
set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    bool isPro = true;
    if (vowels.find(s[0]) == vowels.end()) {
        for (int i = 0; i < s.length(); ++i) {
            if ((i % 2 == 0 && vowels.find(s[i]) != vowels.end()) || (i % 2 == 1 && vowels.find(s[i]) == vowels.end())) {
                isPro = false;
                break;
            }
        }
    } else {
        for (int i = 0; i < s.length(); ++i) {
            if ((i % 2 == 0 && vowels.find(s[i]) == vowels.end()) || (i % 2 == 1 && vowels.find(s[i]) != vowels.end())) {
                isPro = false;
                break;
            }
        }
    }
    if (isPro) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}