#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define printf(...) do{printf(__VA_ARGS__);fflush(stdout);}while(0)
/*

*/
int n, m, cnt=0;
vector<int> diff;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    diff.resize((n+1)*(n+1));
    for (int i = 0; i < m; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for (int j = 0; j < w; ++j) {
            ++diff[(x+j)*(n+1) + y];
            --diff[(x+j)*(n+1) + y+h];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur=0;
        for (int j = 0; j < n; ++j) {
            cur += diff[i*(n+1) + j];
            if (cur % 2 == 1) ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}