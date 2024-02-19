#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, m, j, minTime, pos=0;
map<int, int> dry;
bool isPossible = false;
bool isDry[100001];

int canJump(int pos) {
    for (int i = pos+j; i > pos; --i) {
        if (isDry[i] == true) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> j;
    for (int i = 0; i < m; ++i) {
        int p, t;
        cin >> p >> t;
        dry[t] = p;
    }
    if (j >= n) {
        cout << "0\n";
        return 0;
    }
    isDry[n+1] = true;
    for (auto i : dry) {
        minTime = i.first;
        isDry[i.second] = true;
        int ind = canJump(pos);
        while (ind != -1) {
            if (ind == n+1) {
                isPossible = true;
                break;
            }
            pos = ind;
            ind = canJump(pos);
        }
        if (isPossible) break;
    }
    if (isPossible)
        cout << minTime << "\n";
    else 
        cout << "-1\n";
    return 0;
}