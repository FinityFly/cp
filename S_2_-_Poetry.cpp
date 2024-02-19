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
char v[5] = {'a', 'e', 'i', 'o', 'u'};
string syl[4];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            string l;
            getline(cin, l);
            for (int i = 0; i < l.length(); ++i) {
                l[i] = tolower(l[i]);
            }
            for (int k = l.length()-1; k >= 0; --k) {
                if (find(begin(v), end(v), l[k]) != end(v)) {
                    syl[j] = l.substr(k, l.length()-1);
                    break;
                } else if (l[k] == ' ') {
                    syl[j] = l.substr(k+1, l.length()-1);
                    break;
                } else if (k == 0) {
                    syl[j] = l;
                }
            }
        }
        if (syl[0] == syl[1] && syl[1] == syl[2] && syl[2] == syl[3])
            cout << "perfect\n";
        else if (syl[0] == syl[1] && syl[2] == syl[3])
            cout << "even\n";
        else if (syl[0] == syl[2] && syl[1] == syl[3])
            cout << "cross\n";
        else if (syl[0] == syl[3] && syl[1] == syl[2])
            cout << "shell\n";
        else
            cout << "free\n";
    }
    return 0;
}