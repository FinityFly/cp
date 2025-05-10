#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s, k;
    cin >> n >> s;
    int group[n/s][s], points[n];
    fill(points, points + n, 0);
    for (int i = 0; i < n/s; ++i) {
        for (int j = 0; j < s; ++j) {
            cin >> group[i][j];
        }
    }
    cout << "\n";
    for (int i = 0; i < ((s-1)*n)/2; ++i) {
        int a, b;
        char r;
        cin >> a >> b >> r;
        if (r == 'W') {
            points[a-1] += 3;
        } else if (r == 'L') {
            points[b-1] += 3;
        } else {
            ++points[a-1];
            ++points[b-1];
        }
    }
    cin >> k;
    int output[n/s];
    for (int i = 0; i < n/s; ++i) {
        for (int j = 0; j < k; ++j) {
            int max = -1;
            int index = INT_MAX;
            for (int l = 0; l < s; ++l) {
                if (index != INT_MAX) {
                    if (points[group[i][l]-1] > max && group[i][l] < group[i][index]) {
                        max = points[group[i][l]-1];
                        index = l;
                    }
                } else {
                    if (points[group[i][l]-1] > max) {
                        max = points[group[i][l]-1];
                        index = l;
                    }
                }
            }
            points[group[i][index]-1] = -1;
            output[i] = group[i][index];
        }
    }
    cout << output[0];
    for (int i = 1; i < n/s; ++i){
        cout << ' ' << output[i];
    }
    cout << "\n";
    return 0;
}