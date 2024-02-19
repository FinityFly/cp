#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
set<string> m[400001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        string c;
        cin >> a >> b >> c;
        if (a == 1) {
            if (m[b].find(c) != m[b].end())
                cout << "1\n";
            else
                cout << "0\n";
        } else {
            m[b].insert(c);
        }
    }
    return 0;
}