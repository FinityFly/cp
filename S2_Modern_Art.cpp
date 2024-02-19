#include <bits/stdc++.h>

using namespace std;

int main() {
    bool grid[1000][1000];
    int m, n, k;
    cin >> m >> n >> k;
    for (int i=0;i<k;++i) {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'R') {
            for (int j=0;j<n;++j) {
                grid[b][j] = !grid[b][j];
            }
        } else {
            for (int j=0;j<m;++j) {
                grid[j][b] = !grid[j][b];
            }
        }
    }
    int ans=0;
    for (int i=0;i<m;++i) {
        for (int j=0;j<n;++j) {
            if (grid[i][j]) {
                ++ans;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}