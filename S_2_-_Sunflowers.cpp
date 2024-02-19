#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
int grid[101][101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    bool isIncreasingX = (grid[0][0] < grid[0][1] ? true : false), isIncreasingY = (grid[0][0] < grid[1][0]);
    if (isIncreasingX && isIncreasingY) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << "\n";
        }
    } else if (!isIncreasingX && isIncreasingY) {
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[j][i] << ' ';
            }
            cout << "\n";
        }
    } else if (!isIncreasingX && !isIncreasingY) {
        for (int i = n-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                cout << grid[i][j] << ' ';
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= 0; --j) {
                cout << grid[j][i] << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}