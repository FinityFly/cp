#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
INPUT:

 */
int ans=0, a[100], accessed[100], passers[100];

int closest(int x){
    if(x == 0)
        return x+1;
    else if(a[x] - a[x-1] < a[x+1] - a[x])
        return x-1;
    else
        return x+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");
    int n;
    fin >> n;
    for(int i=0;i<n;++i)
        fin >> a[i];
    sort(a, a+n);
    a[n] = 1001;
    for(int i=0;i<n;++i){
        accessed[closest(i)] = true;
        passers[closest(i)]++;
    }
    for(int i=0;i<n;++i){
        if(accessed[i] != true)
            ++ans;
        if(i > closest(i) && closest(closest(i)) == i && passers[i] == 1 && closest(passers[i]) == 1)
            ++ans;
    }
    fout << ans << "\n";

    return 0;
}