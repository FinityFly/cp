#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, k;
int arr[101];
bool dp[100001];
bool dp_solved[100001];

bool solve(int l) {
    if (dp_solved[l]) return dp[l];
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        if (l - arr[i] >= 0) {
            if (!solve(l - arr[i])) {
                ans = true;
                break;
            }
        }
    }
    dp_solved[l] = true;
    return dp[l] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (solve(k)) cout << "First\n";
    else cout << "Second\n";
    return 0;
}