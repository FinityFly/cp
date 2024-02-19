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
int arr[10001];

bool op(const int& lhs, const int& rhs) {
    return (stoll(to_string(lhs)+to_string(rhs)) > stoll(to_string(rhs)+to_string(lhs)));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n, op);
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    return 0;
}