#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
int n;
string s[200001];
int dp[200001], key[26];

int getValue(string s) {
    int c=0;
    for (int i = 0; i < s.length()-1; ++i) {
        if (s[i] == s[i+1])
            ++c;
    }
    return c;
}

void printDP() {
    for (int i = 0; i < 26; ++i) {
        cout << key[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(key, key+26, -1);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        int charInt = ((int) s[i][s[i].length()-1])-97;
        for (int j = 0; j < 26; ++j) {
            if (key[j] >= 0) {
                bool isMatching = s[key[j]][s[key[j]].length()-1] == s[i][0] ? 1 : 0;
                dp[i] = max(dp[i], dp[key[j]] + isMatching);
            }
        }
        dp[i] += getValue(s[i]);
        if (key[charInt] == -1 || dp[i] > dp[key[charInt]]) {
            key[((int) s[i][s[i].length()-1])-97] = i;
        }
        // printDP();
    }
    cout << dp[n-1] << "\n";
    return 0;
}