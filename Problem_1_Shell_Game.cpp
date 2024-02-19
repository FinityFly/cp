#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n, output=-1;
    int shells[3] = {1, 2, 3}, cnt[3] = {0};
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, g;
        fin >> a >> b >> g;
        swap(shells[a-1], shells[b-1]);
        cnt[shells[g-1]-1]++;
        // for (int j = 0; j < 3; ++j) {
        //     cout << shells[j] << ' ';
        // }
        // cout << "\n";
    }
    for (int i = 0; i < 3; ++i) {
        output = max(output, cnt[i]);
    }
    fout << output << "\n";
    return 0;
}