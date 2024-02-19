#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    int output[26], amax[26], bmax[26];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        fill(amax, amax+26, 0);
        fill(bmax, bmax+26, 0);
        string a, b;
        cin >> a >> b;
        for (int j = 0; j < a.length(); ++j) {
            amax[((int) a[j]) - 97]++;
        }
        for (int j = 0; j < b.length(); ++j) {
            bmax[((int) b[j]) - 97]++;
        }
        for (int j = 0; j < 26; ++j) {
            amax[j] = max(amax[j], bmax[j]);
        }
        for (int j = 0; j < 26; ++j) {
            output[j] += amax[j];
        }
    }
    for (int i = 0; i < 26; ++i) {
        cout << output[i] << "\n";
    }
    return 0;
}