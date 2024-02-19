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

bool isPrefix(string s, string p) {
    if (p.length() > s.length()) {
        return false;
    } else if (s.substr(0, p.length()) == p) {
        return true;
    } else {
        return false;
    }
}

bool isSuffix(string s, string p) {
    if (p.length() > s.length()) {
        return false;
    } else if (s.substr(s.length()-p.length(), p.length()) == p) {
        return true;
    } else {
        return false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s[3];
        for (int j = 0; j < 3; ++j) {
            cin >> s[j];
        }
        if (isPrefix(s[0], s[1]) || isPrefix(s[1], s[0]) || isPrefix(s[0], s[2]) || isPrefix(s[2], s[0]) || isPrefix(s[1], s[2]) || isPrefix(s[2], s[1]) || isSuffix(s[0], s[1]) || isSuffix(s[1], s[0]) || isSuffix(s[0], s[2]) || isSuffix(s[2], s[0]) || isSuffix(s[1], s[2]) || isSuffix(s[2], s[1]))
            cout << "No\n";
        else 
            cout << "Yes\n";
    }
    return 0;
}