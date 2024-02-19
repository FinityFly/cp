#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*
4 spaces
*/
int width;
vector<string> sign;
string words[6] = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> width;
    int line = 0;
    for (int i = 0; i < 6;) {
        sign.push_back(words[i]);
        while (sign[line].length() - words[i].length() + 1 < words[i+1].length()) {
            sign[line] += '.' + words[i+1];
            ++i;
        }
        ++line;
        ++i;
    }
    for (int i = 0; i < sign.size(); ++i) {
        cout << sign[i] << "\n";
    }
    return 0;
}