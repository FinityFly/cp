#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
int n, q;
int a[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        int x, ind=-1;
        cin >> x;
        for (int i = 0; i < n; ++i) {
            if (x % a[i] != 0) {
                ind = i+1;
                break;
            }
        }
        cout << ind << "\n";
    }
    return 0;
}