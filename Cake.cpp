#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, minValue=INT_MAX, a[101], best=1;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minValue = min(minValue, a[i]);
    }
    for (int fac = 2; fac <= minValue; ++fac) {
        bool isGood = true;
        for (int j = 0; j < n; ++j) {
            if ((double) floor((double) a[j] / (double) fac) != (double) a[j] / (double) fac || a[j] / fac == 0) {
                isGood = false;
                break;
            }
        }
        if (isGood) best = max(best, fac);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i]/best << " ";
    }
    return 0;
}