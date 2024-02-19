#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n, b, occ[4];
    cin >> n >> b;
    int ans=n, arr[n][2];
    for(int i=0;i<n;++i) cin >> arr[i][0] >> arr[i][1];
    for(int i=2;i<b;i+=2){ // x
        for(int j=2;j<b;j+=2){ // y
            fill(occ, occ+4, 0);
            for(int k=0;k<n;++k){
                if(arr[k][0] > i && arr[k][1] > j)
                    ++occ[0];
                else if(arr[k][0] < i && arr[k][1] > j)
                    ++occ[1];
                else if(arr[k][0] < i && arr[k][1] < j)
                    ++occ[2];
                else if(arr[k][0] > i && arr[k][1] < j)
                    ++occ[3];
            }
            ans = min(ans, max(max(occ[0], occ[1]), max(occ[2], occ[3])));
        }
    }
    cout << ans << "\n";
    return 0;
}