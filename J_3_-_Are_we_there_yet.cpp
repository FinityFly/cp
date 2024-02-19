#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int d[4];
int output[5];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d[0] >> d[1] >> d[2] >> d[3];
    for (int i = 0; i < 5; ++i) {
        fill(output, output+5, 0);
        for (int j = i-1; j >= 0; --j) {
            output[j] = output[j+1] + d[j];
        }
        for (int j = i+1; j < 5; ++j) {
            output[j] = output[j-1] + d[j-1];
        }
        for (int j = 0; j < 5; ++j) {
            cout << output[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}