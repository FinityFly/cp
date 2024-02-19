#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
/*

*/
string s;

bool isMonk(string a) {
    size_t ita = a.find("ANA");
    size_t itb = a.find("BAS");
    while (ita != string::npos || itb != string::npos) {
        string temp;
        if (ita != string::npos) {
            temp = a.substr(0, ita) + 'A' + a.substr(ita+3, a.length()-1);
            a = temp;
        } else if (itb != string::npos) {
            temp = a.substr(0, itb) + 'A' + a.substr(itb+3, a.length()-1);
            a = temp;
        }
        ita = a.find("ANA");
        itb = a.find("BAS");
    }
    if (a == "A") return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> s) {
        if (s != "X") {
            if (isMonk(s)) cout << "YES\n";
            else cout << "NO\n";
        } else break;
    }
    return 0;
}