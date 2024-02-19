#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*
Simple line with text
Now with a mix of long and short words put
*/
string s;
int cnt;

bool isCharacter(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        cnt=0;
        getline(cin, s);
        int l=0;
        for (int i = 0; i < s.length(); ++i) {
            if (isCharacter(s[i])) {
                ++l;
                if (i == s.length()-1 && l > 3) ++cnt;
            } else {
                if (l > 3) ++cnt;
                l=0;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}