#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */
int a[101], b[101], order[101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n;
    fin >> n;
    for(int i=1;i<=n;++i){
        fin >> a[i];
    }
    for(int i=1;i<=n;++i){
        fin >> b[i];
    }
    for(int i=0;i<3;++i){
        for(int j=1;j<=n;++j){
            order[j] = b[a[j]];
        }
        for(int j=1;j<=n;++j){
            b[j] = order[j];
        }
    }
    for(int i=1;i<=n;++i){
        fout << b[i] << "\n";
    }
    return 0;
}