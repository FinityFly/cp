#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */
string s;
bool checkPal(string s){
    int i=0, a=0, b=s.size()-1;
    while((b-i)-(a+i) >= 0){
        if(s[a+i] != s[b-i])
            return false;
        ++i;
    }
    return true;
}
string solve(string s){
    int n = s.size();
    for(int i=n;i>1;--i){
        for(int j=0;j<n-i+1;++j) {
            cout << s.substr(j,i) << "\n";
            if (checkPal(s.substr(j,i))){
                return s.substr(j,i);
            }
        }
    }
    return "void";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cout << "\n" << solve(s) << "\n";
    return 0;
}