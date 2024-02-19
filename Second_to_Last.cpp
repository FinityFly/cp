#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
pair<int, int> arr[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr[i] = {a, i+1};
    }
    sort(arr, arr+n, [](auto &lhs, auto &rhs) {
        return lhs.first > rhs.first;
    });
    cout << arr[1].second << "\n";
    return 0;
}