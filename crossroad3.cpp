#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */

bool sortcol(pair<int, int> v1, pair<int, int> v2) {
    return v1.first < v2.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int n, ans=0;
    fin >> n;
    vector< pair<int, int> > arr(n);
    for(int i=0;i<n;++i){
        fin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), sortcol);
    for(int i=0;i<n;++i){
        if(arr[i].first + arr[i].second > arr[i+1].first)
            arr[i+1].first = arr[i].first + arr[i].second;
        if(i==n-2) {
            ans = arr[i+1].first + arr[i+1].second;
            break;
        }
    }
    if (n == 1){
        fout << arr[0].first + arr[0].second << "\n";
    } else {
        fout << ans << "\n";
    }
    return 0;
}