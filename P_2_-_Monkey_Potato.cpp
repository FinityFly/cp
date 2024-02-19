#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int k, d, m=10;
bool hasZero = false;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> d;
    for (int i = 0; i < d; ++i) {
        int a;
        cin >> a;
        if (a == 0) hasZero = true;
        else m = min(m, a);
    }
    if (hasZero && m == 10) {
        cout << "-1\n";
    } else if (hasZero && m != 10) {
        string s = string(k, '0');
        s[0] = char(m)+'0';
        s[k-1] = char(m)+'0';
        cout << s << "\n";
    } else if (!hasZero && m != 10) {
        string s = string(k, char(m)+'0');
        cout << s << "\n";
    }
    return 0;
}