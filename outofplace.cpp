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
    int n, swaps=-1;
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    fin >> n;
    vector<int> values(n), sorted(n);
    for(int i=0;i<n;++i){
        fin >> values[i];
        sorted[i] = values[i];
    }
    sort(sorted.begin(), sorted.end());
    for(int a=0;a<n;a++){
        if(sorted[a] != values[a]){
            swaps++;
        }
    }
    swaps = max(swaps, 0);
    fout << swaps << "\n";
    return 0;
}