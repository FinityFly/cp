#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, s, t, cnt=0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a*2 >= s && a*2 <= t) ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}