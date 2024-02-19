#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
int n, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << a + 2*c << " ";
    }
    return 0;
}