#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, t;
string output;
int mindist=INT_MAX;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        string a;
        int b;
        cin >> a >> b;
        if (abs(t-b) < mindist) {
            mindist = abs(t-b);
            output = a;
        }
    }
    cout << output << "\n";
    return 0;
}