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
bool c[3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    c[0] = true;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A')
            swap(c[0], c[1]);
        else if (s[i] == 'B')
            swap(c[1], c[2]);
        else
            swap(c[0], c[2]);
    }
    if (c[0]) cout << '1';
    else if (c[1]) cout << '2';
    else cout << '3';
    return 0;
}