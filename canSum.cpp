#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */

int m, n;
int arr[10];
bool dp[1000];
bool dp_solved[1000];

bool canSum(int total) {
    if (dp_solved[total]) {
        return dp[total];
    }
    if (total == 0) {
        return true;
    }
    for (int i = 0; i < m; ++i) {
        if (total - arr[i] >= 0 && canSum(total - arr[i])) {
            dp[total] = true;
            dp_solved[total] = true;
            return true;
        }
    }
    dp[total] = false;
    dp_solved[total] = true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    if (canSum(n)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}