#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
string s;
set<int> ints;
bool isNumber = false;
int numberIndex;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] < 97) {
            if (isNumber == false) {
                isNumber = true;
                numberIndex = i;
            }
        } else {
            if (isNumber == true) {
                ints.insert(stoi(s.substr(numberIndex, i-numberIndex)));
                isNumber = false;
            }
        }
    }
    if (isNumber == true) {
        ints.insert(stoi(s.substr(numberIndex, s.length()-numberIndex)));
    }
    cout << ints.size() << "\n";
    return 0;
}