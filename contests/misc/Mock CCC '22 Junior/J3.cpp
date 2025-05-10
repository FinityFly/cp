#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

void fillPrefixSum(int arr[], int n, int prefixSum[]) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int s[n], prefixSum[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    fillPrefixSum(s, n, prefixSum);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (prefixSum[index-1] == prefixSum[n-1] - prefixSum[index-1]) {
            cout << index << "\n";
            return 0;
        }
        ++index;
    }
    cout << "Andrew is sad.\n";
    return 0;
}