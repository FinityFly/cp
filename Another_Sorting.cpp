#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
int arr[100001];

bool op(const int& lhs, const int& rhs) {
    string l_str = to_string(lhs), r_str = to_string(rhs);
    if (l_str[l_str.length()-1] < r_str[r_str.length()-1]) {
        return true;
    } else if (l_str[l_str.length()-1] > r_str[r_str.length()-1]) {
        return false;
    } else {
        if (lhs < rhs) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n, op);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}