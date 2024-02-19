#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

 */

int n, target;
int arr[10];
vector<int> dp[100];
bool dp_solved[100];

vector<int> howSum(int total) {
    if (dp_solved[total]) {
        return dp[total];
    }
    if (total == 0) {
        return vector<int>();
    } else if (total < 0) {
        return vector<int>(-1);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> output = howSum(total - arr[i]);
        if (output[0] != -1) {
            output.push_back(arr[i]);
            dp[total] = output;
            dp_solved[total] = true;
            return output;
        }
    }
    dp[total] = vector<int>(-1);
    return vector<int>(-1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> target;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> output = howSum(target);
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << ' ';
    }
    cout << "\n";
    return 0;
}