#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int a, b, c, d;

int solve(int x, int y, int cnt) {
    if (x == c && y == d) return cnt;
    if (cnt < 6) {
        int ans=INT_MAX;
        if (x+1 < 9 && y+2 < 9) ans = min(ans, solve(x+1, y+2, cnt+1));
        if (x-1 > 0 && y+2 < 9) ans = min(ans, solve(x-1, y+2, cnt+1));
        if (x+2 < 9 && y+1 < 9) ans = min(ans, solve(x+2, y+1, cnt+1));
        if (x-2 > 0 && y+1 < 9) ans = min(ans, solve(x-2, y+1, cnt+1));
        if (x+2 < 9 && y-1 > 0) ans = min(ans, solve(x+2, y-1, cnt+1));
        if (x-2 > 0 && y-1 > 0) ans = min(ans, solve(x-2, y-1, cnt+1));
        if (x+1 < 9 && y-2 > 0) ans = min(ans, solve(x+1, y-2, cnt+1));
        if (x-1 > 0 && y-2 > 0) ans = min(ans, solve(x-1, y-2, cnt+1));
        return ans;
    } else return INT_MAX;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    cout << solve(a, b, 0) << "\n";
    return 0;
}