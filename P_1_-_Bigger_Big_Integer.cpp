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
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        if ((int) s[i]-'0' > (int) s[i-1]-'0') {
            swap(s[i], s[i-1]);
            cout << s;
            return 0;
        }
    }
    cout << s;
    return 0;
}