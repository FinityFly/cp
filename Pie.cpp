#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n, m;
double rem=100, arr[31];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        double p;
        cin >> a >> p;
        arr[a-1] += rem * (p/100);
        rem = rem - (rem * (p/100));
    }
    for (int i = 0; i < n; ++i) {
        cout << std::fixed << setprecision(6) << arr[i]/100 << "\n";
    }
    return 0;
}