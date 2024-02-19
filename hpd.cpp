#include <bits/stdc++.h>

using namespace std;

string m;
int n;
bool isPal=false;

bool checkPal(string s){
    int i=0, a=0, b=s.size()-1;
    while((b-i)-(a+i) >= 0){
        if(s[a+i] != s[b-i])
            return false;
        ++i;
    }
    return true;
}


void solve(){
    int ans=1;
    n = m.size();
    for(int i=n;i>1;--i){
        for(int j=0;j<=n-i;++j) {
            if (checkPal(m.substr(j,i))){
                ans=i;
                isPal=true;
            }
            if(isPal) break;
        }
        if(isPal) break;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    solve();
    return 0;
}