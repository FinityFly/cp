#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int t, n;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        stack<int> top, branch;
        int curind=1;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            top.push(a);
        }
        bool possible=false;
        while (!top.empty()) {
            if (top.top() == curind) {
                ++curind;
                top.pop();
            } else if (!branch.empty() && branch.top() == curind) {
                ++curind;
                branch.pop();
            } else {
                branch.push(top.top());
                top.pop();
            }
            if (curind == n+1) possible = true;
        }
        while (!branch.empty()) {
            if (branch.top() == curind) {
                ++curind;
                branch.pop();
            } else {
                break;
            }
            if (curind == n+1) possible = true;
        }
        if (possible) cout << "Y\n";
        else cout << "N\n";
    }
    
    return 0;
}