#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, state, cnt=0;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    state = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] != state) {
            ++cnt;
            state = s[i];
        }
    }
    if (s[n-1] == '1') ++cnt;
    cout << cnt << "\n";
    return 0;
}