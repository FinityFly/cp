#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    char b;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        for(int j=0;j<a;++j)
            cout << b << "\n";
    }
    return 0;
}