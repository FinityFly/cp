#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    ifstream fin("cownomics.in");
//    ofstream fout("cownomics.out");
    int n, m, ans=0;
    cin >> n >> m;
    char spotty[n][m], plain[n][m];
    vector<char> spottyset, plainset;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> spotty[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> plain[i][j];
    for(int i=0;i<m;++i){
        spottyset.clear();
        plainset.clear();
        for(int j=0;j<n;++j)
            if(find(spottyset.begin(), spottyset.end(), spotty[j][i]) == spottyset.end())
                spottyset.push_back(spotty[j][i]);
        for(int j=0;j<n;++j)
            if(find(plainset.begin(), plainset.end(), plain[j][i]) == plainset.end())
                plainset.push_back(plain[j][i]);
        for(int j=0;j<spottyset.size();++j){
            if(find(plainset.begin(), plainset.end(), spotty[j][i]) != plainset.end())
                break;
            else if(find(plainset.begin(), plainset.end(), spotty[j][i]) == plainset.end() && j == spottyset.size()-1)
                ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}