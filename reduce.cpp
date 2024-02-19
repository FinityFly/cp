#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    int n, minx=40001, miny=40001, maxx=0, maxy=0, ans;
    cin >> n;
    int v[2][n], sorted[2][n];
    for(int i=0;i<n;++i) cin >> v[i][0] >> v[i][1];
    copy(v[0], v[0]+n, sorted[0]);
    copy(v[1], v[1]+n, sorted[1]);
    sort(v[0], v[0]+n);
    sort(v[1], v[1]+n);
    ans = (maxx - minx) * (maxy - miny);
    for(int i=0;i<n;++i){
        int tminx = minx, tminy = miny, tmaxx = maxx, tmaxy = maxy;
        if(v[0][i] < minx)
            tminx = sorted[0][n-2];
        else if(v[0][i] > maxx)
            tmaxx = v[0][i];
        if(v[1][i] < miny)
            tminy = v[1][i];
        else if(v[1][i] > maxy)
            tmaxy = v[1][i];
        cout << tmaxx << " " << tminx << " " << tmaxy << " " << tminy << "\n\n";
        if((tmaxx - tminx) * (tmaxy - tminy) < ans)
            ans = (tmaxx - tminx) * (tmaxy - tminy);
        cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}