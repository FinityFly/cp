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
    ifstream fin("wordlist.txt");
    ofstream fout("output.txt");

    string input, word, output[10];
    vector<string> ogvector, sortedvector;

    for(int i=0;i<1275;++i) {
        fin >> input;
        ogvector.push_back(input);
        sort(input.begin(), input.end());
        sortedvector.push_back(input);
    }
    cout << "Stored | Paste input below\n";
    // main
    for(int j=0;j<10;++j) {
        cin >> word;
        fout << "\nWord #" << j << ": " << word << "\n\n";
        sort(word.begin(), word.end());
        for(int k=0;k<1275;++k){
            fout << ogvector[k] << ": " << word << " - " << sortedvector[k] << "\n";
            if(word == sortedvector[k]){
                output[j] = ogvector[k];
                break;
            }
        }
    }
    // print out
    for(int l=0;l<10;++l)
        if(l != 9)
            cout << output[l] << ",";
        else
            cout << output[l] << "\n";
    return 0;
}

/*
teimbe
ftrere
ghrcipa
sserhuk
ynewith
naohmpt
eipnsr
ricctlee
spyikp
uarhtr
*/