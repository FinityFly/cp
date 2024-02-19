#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans=0, cur;
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    fin >> n >> k;
    int sizes[1000];
    for(int i=0;i<n;++i){
        fin >> sizes[i];
    }
    for(int i=0;i<n;++i){
        cur=0;
        for(int j=0;j<n;++j){
            if(sizes[j] <= sizes[i] + k && sizes[j] >= sizes[i])
                ++cur;
        }
        ans = (cur > ans) ? cur : ans;
    }
    fout << ans << "\n";
    return 0;
}