#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, diff, diff2=-1, pre, pre2;
int arr[5];
bool isArith = true, used = false;;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (i == 1) {
            diff = abs(pre-cur);
        } else if (i == 2) {
            if (abs(pre-cur) % diff != 0) {
                diff2 = abs(pre-cur);
                pre2 = pre;
                used = true;
            }
        } else if (i == 3) {
            if (abs(pre-cur) % diff2 == 0) {
                diff = diff2;
            }
        }
         else if (i > 2) {
            if (abs(pre-cur) % diff != 0 && used == false) {
                diff2 = abs(pre-cur);
                used = true;
            } else if (abs(pre-cur) % diff != 0 && used == true && abs(pre-cur) % diff2 != 0 && abs(cur-pre2) % diff != 0) {
                isArith = false;
                break;
            } else if (abs(pre-cur) % diff2 == 0 && i == 3) {
                diff = diff2;
            }
        }
        pre = cur;
    }
    if (isArith) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}