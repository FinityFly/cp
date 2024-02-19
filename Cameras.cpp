#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/
int n, k, r, cnt=0;
int c[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> r;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        int b = a-r+1 < 1 ? 1 : a-r+1;
        for (int j = b; j < a+r; ++j) {
            if (j > 100001) break;
            ++c[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] <= 2) {
            ++cnt;
            for (int j = i; j < i+2*(r-1)+1; ++j) {
                if (j >= 100001) break;
                ++c[j];
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}