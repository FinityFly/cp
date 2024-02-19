#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/

string input, token;
stack<double> nums;
double n1, n2;
vector<string> insplit;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, input);
    size_t pos = 0;
    while((pos = input.find(' ')) != string::npos) {
        token = input.substr(0, pos);
        insplit.push_back(token);
        input.erase(0, pos+1);
    }
    insplit.push_back(input);
    for (string c : insplit) {
        if (c == "+") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push(n2 + n1);
        } else if (c == "-") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push(n2 - n1);
        } else if (c == "*") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push(n2 * n1);
        } else if (c == "/") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push(n2 / n1);
        } else if (c == "%") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push((int) n2 % (int) n1);
        } else if (c == "^") {
            n1 = nums.top(); nums.pop();
            n2 = nums.top(); nums.pop();
            nums.push(pow(n2, n1));
        } else {
            nums.push((double) stoi(c));
        }
    }
    cout << fixed << setprecision(1) << nums.top() << "\n";
    return 0;
}