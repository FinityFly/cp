#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int r, c, n, a;

bool op (const vector<int>& lhs, const vector<int>& rhs) {
    return lhs[a] < rhs[a];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        --a;
        stable_sort(grid.begin(), grid.end(), op);
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}