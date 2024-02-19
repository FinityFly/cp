#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
map<char, char> shift;
vector<char> m1 = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
vector<char> m2 = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.length(); ++i) {
        shift[s2[i]] = s1[i];
        if (find(m1.begin(), m1.end(), s1[i]) != m1.end()) m1.erase(find(m1.begin(), m1.end(), s1[i]));
        if (find(m2.begin(), m2.end(), s2[i]) != m2.end()) m2.erase(find(m2.begin(), m2.end(), s2[i]));
        if (m1.size() == 0 || m2.size() == 0) break;
    }
    if (m1.size() == 1) {
        for (int i = 0; i < m2.size(); ++i) {
            shift[m2[i]] = m1[0];
        }
    }
    getline(cin, s3);
    for (int i = 0; i < s3.length(); ++i) {
        if (shift.find(s3[i]) != shift.end()) {
            cout << shift[s3[i]];
        } else {
            cout << '.';
        }
    }
    cout << "\n";
    return 0;
}