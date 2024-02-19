#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d, n, total = 0, min = INT_MAX;
    cin >> a >> b >> c >> d >> n;
    for (int i = 0; i * a <= n; ++i) {
        for (int j = 0; j * b <= n; ++j) {
            for (int k = 0; k * c <= n; ++k) {
                for (int l = 0; l * d <= n; ++l) {
                    if (i * a + j * b + k * c + l * d == n) {
                        cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << l << "\n";
                        ++total;
                        if (i + j + k + l < min) {
                            min = i + j + k + l;
                        }
                    }
                }
            }
        }
    }
    cout << "Total combinations is " << total << ".\n";
    cout << "Minimum number of tickets to print is " << min << ".\n";
    return 0;
}