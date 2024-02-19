#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
/*

*/
int t, n, cnt=0, out=0;
int s[50002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t >> n;
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    sort(s, s+n+1, [](auto &lhs, auto &rhs) {
        return abs(lhs) < abs(rhs);
    });
    for (int i = 1; i <= n; ++i) {
        if (out + abs(s[i-1]-s[i]) < t) {
           out += abs(s[i-1]-s[i]);
           ++cnt;
        } else {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}