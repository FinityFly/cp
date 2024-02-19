#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n, out=0;
stack<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            s.pop();
        } else {
            s.push(a);
        }
    }
    while (!s.empty()) {
        out += s.top();
        s.pop();
    }
    cout << out << "\n";
    return 0;
}