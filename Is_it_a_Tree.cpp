#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int grid[4][4];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> grid[i][j];
        }
    }
    if ((grid[1][2] + grid[1][3] + grid[2][3] == 3) || (grid[0][2] + grid[0][3] + grid[2][3] == 3)) {
        cout << "No\n";
    } else if (grid[0][1] + grid[0][2] + grid[0][3] + grid[1][2] + grid[1][3] + grid[2][3] == 3) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}