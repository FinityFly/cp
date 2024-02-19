#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int n;
string s, out;
map<char, int> convert = {{'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}, {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'}};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        out.clear();
        for (int j = 0; j < 10; ++j) {
            if (convert.find(s[j]) != convert.end())
                out += convert[s[j]];
            else
                out += s[j];
            if (j == 2 || j == 5) out += '-';
        }
        cout << out << "\n";
    }
    return 0;
}