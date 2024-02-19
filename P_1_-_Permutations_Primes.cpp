#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/
int n;
vector<int> evens, odds;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n < 5) {
        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "-1\n";
        } else if (n == 3) {
            cout << "-1\n";
        } else if (n == 4) {
            cout << "-1\n";
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i != 4 && i != 5) {
                if (i % 2 == 0)
                    evens.push_back(i);
                else
                    odds.push_back(i);
            }
        }
        for (int i = 0; i < evens.size(); ++i) {
            cout << evens[i] << " ";
        }
        cout << "4 5 " << odds[0];
        for (int i = 1; i < odds.size(); ++i) {
            cout << " " << odds[i];
        }
        cout << "\n";
    }
    return 0;
}