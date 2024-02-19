#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int n, m=-1, out=0;
int cnt[6];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "red") {
            ++cnt[0];
            if (cnt[0] > m) m = cnt[0];
        } else if (s == "orange") {
            ++cnt[1];
            if (cnt[1] > m) m = cnt[1];
        } else if (s == "yellow") {
            ++cnt[2];
            if (cnt[2] > m) m = cnt[2];
        } else if (s == "green") {
            ++cnt[3];
            if (cnt[3] > m) m = cnt[3];
        } else if (s == "blue") {
            ++cnt[4];
            if (cnt[4] > m) m = cnt[4];
        } else {
            ++cnt[5];
            if (cnt[5] > m) m = cnt[5];
        }
    }
    for (int i = 0; i < 6; ++i) {
        if (cnt[i] <= m) out += cnt[i];
    }
    cout << out << "\n";
    return 0;
}rs