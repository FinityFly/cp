#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, c=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a > b)
            ++c;
    }
    cout << c;
    return 0;
}