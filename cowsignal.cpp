#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:
5 4 2
XXX.
X..X
XXX.
X..X
XXX.
 */
// print instead of storing to output later
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int m, n, k;
    string x;
    fin >> m >> n >> k;
    char signal[m][n], output[m*k][n*k], temp1;
    string temp2;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            fin >> temp1;
            signal[i][j] = temp1;
            for(int l=0;l<k;++l){
                output[i*k][j*k+l] = temp1;
            }
        }
        temp2 = output[i*k];
        for(int l=0;l<k;++l){
            for(int o=0;o<n*k;++o){
                output[i*k+l][o] = temp2[o];
            }
        }
    }
    for(int i=0;i<m*k;++i){
        for(int j=0;j<n*k;++j){
            fout << output[i][j];
        }
        fout << "\n";
    }
    return 0;
}