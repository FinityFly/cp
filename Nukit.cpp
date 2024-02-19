#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
int moves[5][4] = { 
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};
bool dp[31][31][31][31];

int main () {
    bool dp[31][31][31][31]={false};
    cin >> n;
    for (int a = 0; a < 30; ++a) {
        for (int b = 0; b <= 30; ++b) {
            for (int c = 0; c <= 30; ++c) {
                for (int d = 0; d <= 30; ++d) {
                    for (int o = 0; o < 5; ++o) {
                        if (a >= moves[o][0] && b >= moves[o][1] && c >= moves[o][2] && d >= moves[o][3]) {
                            if (dp[a-moves[o][0]][b-moves[o][1]][c-moves[o][2]][d-moves[o][3]] == false) {
                                dp[a][b][c][d] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c >> d;
        if (dp[a][b][c][d])
            cout << "Patrick\n";
        else
            cout << "Roland\n";
    }
    return 0;
}