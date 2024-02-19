#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
/*

*/

int n;
string s;

int main() {
  cin >> n >> s;
  for (int i = 0; i < s.length(); ++i) {
    int shifted = (int)s[i] - ((i+1)*3+n);
    while (shifted < 65) shifted += 26;
    cout << (char) shifted;
  }
  cout << "\n";
  return 0;
}