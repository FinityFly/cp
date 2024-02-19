#include <bits/stdc++.h>
#include <fstream>

using namespace std;

/*
INPUT:

 */

int n, a[1009], b[1009], length[1009];
int maxlen = 0;

int main()
{
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    fin >> n;
    for(int i=1;i<=n;i++){
        fin >> a[i] >> b[i];
        length[i] = 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=a[i];j<b[i];j++)
            length[j]++;

    for(int i=1;i<=n;i++){
        for(int j=a[i];j<b[i];j++)
            length[j]--;
        int len = 0;
        for(int j=1;j<1000;j++)
            if(length[j] > 0)
                len++;
        maxlen = max(maxlen, len);
        for(int j=a[i];j<b[i];j++)
            length[j]++;
    }
    fout << maxlen << endl;
    return 0;
}