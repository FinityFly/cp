#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
string s;
int t, e=0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    cout << t << "\n";
    for (int d = 120; d > 0; --d) {
        if ((t > 7*60 && t < 10*60) || (t > 15*60 && t < 19*60)) {
            e += 1;
            t += 1;
        } else {
            t += 2;
            e += 2;
        }
    }
    cout << e << "\n";
    return 0;
}