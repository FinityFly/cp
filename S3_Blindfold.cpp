#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, c, n;
    vector< pair<int, int> > output;
    cin >> r >> c;
    char m[r][c];
    string a;
    for (int i = 0; i < r; ++i) {
        cin >> a;
        for (int j = 0; j < c; ++j) {
            m[i][j] = a[j];
        }
    }
    cin >> n;
    char moves[n];
    for (int i = 0; i < n; ++i) {
        cin >> moves[i];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (m[i][j] != 'X') {
                for (int k = 0; k < 4; ++k) {
                    int x = i, y = j, rot = k;
                    bool isPossible = true;
                    for (int l = 0; l < n; ++l) {
                        if (m[x][y] != 'X' && x >= 0 && y >= 0 && x < r && y < c) {
                            if (moves[l] == 'F') {
                                if (rot == 0) {
                                    --x;
                                } else if (rot == 1) {
                                    ++y;
                                } else if (rot == 2) {
                                    ++x;
                                } else {
                                    --y;
                                }
                            } else if (moves[l] == 'R') {
                                rot = (rot + 1) % 4;
                            } else {
                                rot = (rot - 1) % 4;
                            }
                        } else {
                            isPossible = false;
                            break;
                        }
                    }
                    if (isPossible && m[x][y] != 'X' && x >= 0 && y >= 0 && x < r && y < c) {
                        output.push_back(make_pair(x, y));
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (find(output.begin(), output.end(), make_pair(i, j)) != output.end()) {
                cout << '*';
            } else {
                cout << m[i][j];
            }
        }
        cout << "\n";
    }
    return 0;
}