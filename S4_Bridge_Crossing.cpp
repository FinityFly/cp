#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int m, n;
int dp[101];
bool dp_solved[101];

void printQueue(queue<pair<string, int>> q) {
    while (!q.empty()) {
        cout << q.front().first << ", " << q.front().second << " | ";
        q.pop();
    }
    cout << "\n";
}

int mintime(int pos, queue<pair<string, int>> q) {
    cout << "pos: " << pos << "\n";
    printQueue(q);
    if (dp_solved[pos]) return dp[pos];
    if (pos == n-1) {
        dp[pos] = 0;
        dp_solved[pos] = true;
        return 0;
    }
    queue<pair<string, int>> temp = q;
    int w=-1;
    for (int i = 0; i < m && i+pos < n; ++i) {
        w = max(temp.front().second, w);
        temp.pop();
        dp[pos+i] = min(dp[pos+i], mintime(pos+i+1, temp)+w);
        dp_solved[pos+i] = true;
    }
    cout << "return: " << dp[n-1] << "\n";
    return dp[n-1];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue<pair<string, int>> q;
    fill(dp, dp+101, INT_MAX);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        string a;
        int b;
        cin >> a >> b;
        q.push({a, b});
    }
    cout << mintime(0, q) << "\n";
    return 0;
}