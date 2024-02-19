#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n;
int arr[1501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < n; ++j) {
            if (a[j] == 'S')
                ++arr[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        string output;
        for (int j = 0; j < n; ++j) {
            if (n-arr[j] <= i) cout << 'S';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}