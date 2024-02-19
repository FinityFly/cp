#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */
int n, ans=0, arr[11];

int main()
{
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");
    fill(arr, arr+11, 2);
    fin >> n;
    int a[n], b[n];
    for(int i=0;i<n;++i){
        fin >> a[i] >> b[i];
        if(arr[a[i]] == 2)
            arr[a[i]] = b[i];
    }
    for(int i=0;i<n;++i){
        int id = a[i];
        if(arr[id] > b[i]){
            arr[id] = 0;
            ++ans;
        }else if(arr[id] < b[i]){
            arr[id] = 1;
            ++ans;
        }

    }
    fout << ans << "\n";
    return 0;
}