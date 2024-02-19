#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, cnt=0;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "face") ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}