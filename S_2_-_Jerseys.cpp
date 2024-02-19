#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, m, cnt=0;
char jerseys[1000002], requests[1000002];
map<char, int> value = {{'S', 0}, {'M', 1}, {'L', 2}};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> jerseys[i];
    }
    for (int i = 0; i < m; ++i) {
        char a;
        int b;
        cin >> a >> b;
        if (requests[b] == 0 || value[requests[b]] > value[a]) {
            requests[b] = a;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (value[requests[i]] <= value[jerseys[i]] && requests[i] != 0) ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}