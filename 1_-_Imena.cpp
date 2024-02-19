#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
string s;
vector<string> sen;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin.ignore();
    getline(cin, s);
    size_t pos = 0;
    string token;
    while ((pos = s.find('.')) != string::npos || (pos = s.find('?')) != string::npos || (pos = s.find('!')) != string::npos) {
        token = s.substr(0, pos) + " ";
        sen.push_back(token);
        s.erase(0, pos+2);
    }
    for (int i = 0; i < n; ++i) {
        int cnt=0;
        vector<string> words;
        size_t p = 0;
        string t;
        while ((p = sen[i].find(' ')) != string::npos) {
            t = sen[i].substr(0, p);
            words.push_back(t);
            sen[i].erase(0, p+1);
        }
        for (int j = 0; j < words.size(); ++j) {
            if (isalpha(words[j][0]) && isupper(words[j][0])) {
                bool valid = true;
                for (int k = 1; k < words[j].length(); ++k) {
                    if (!isalpha(words[j][k]) || isupper(words[j][k])) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ++cnt;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
