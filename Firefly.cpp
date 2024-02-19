#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, h, out=INT_MAX, cnt;
int diff[500002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            ++diff[1];
            --diff[a+1];
        } else {
            ++diff[h-a+1];
            --diff[h+1];
        }
    }
    for (int i = 1; i <= h; ++i) {
        diff[i] += diff[i-1];
        if (diff[i] < out) {
            out = diff[i];
            cnt = 1;
        } else if (diff[i] == out) ++cnt;
    }
    cout << out << " " << cnt << "\n";
    return 0;
}