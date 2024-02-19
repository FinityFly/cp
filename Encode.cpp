#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n;
string s, o;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, s);
    n = stoi(s);
    n = n % 26;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            if ((int) s[i] >= 65 && (int) s[i] <= 90 && (int) s[i]-n < 65) {
                o += (char) 91 - (65 - ((int) s[i] - n));
            } else if ((int) s[i] >= 97 && (int) s[i] <= 122 && (int) s[i]-n < 97) {
                o += (char) 123 - (97 - ((int) s[i] - n));
            } else if ((int) s[i] >= 65 && (int) s[i] <= 90 && (int) s[i]-n > 90) {
                o += (char) 64 + (((int) s[i] - n) - 90);
            } else if ((int) s[i] >= 97 && (int) s[i] <= 122 && (int) s[i]-n > 122) {
                o += (char) 96 + (((int) s[i] - n) - 122);
            } else {
                o += (char) ((int) s[i] - n);
            }
        } else o += ' ';
    }
    cout << o << "\n";
    return 0;
}