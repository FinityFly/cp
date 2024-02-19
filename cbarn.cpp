#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans, arr[1009], n, sum=0, a, b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    fin >> n;
    ans = n*n*100;
    for(int i=0;i<n;++i){
        fin >> arr[i];
        sum += arr[i];
    }
    for(int i=0;i<n;i++){
        a = sum, b = 0;
        for(int j=0;j<n-1;j++){
            a -= arr[(i+j)%n];
            b += a;
        }
        ans = min(ans, b);
    }
    fout << ans << "\n";
    return 0;
}