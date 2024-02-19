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

void printStack(stack<string> a) {
    while(!a.empty()){
      cout<<a.top()<<" ";
      a.pop();
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        getline(cin, s);
        if (s != "0") {
            istringstream iss(s);
            vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
            stack<string> n;
            for (int i = tokens.size()-1; i >= 0; --i) {
                if (tokens[i] == "+" || tokens[i] == "-") {
                    string s1 = n.top();
                    n.pop();
                    string s2 = n.top();
                    n.pop();
                    string temp = s1 + " " + s2 + " " + tokens[i];
                    n.push(temp);
                } else {
                    n.push(tokens[i]);
                }
                // printStack(n);
            }
            cout << n.top() << "\n";
        } else break;
    }
    return 0;
}