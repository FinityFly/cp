#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int low, high;
    cin >> low >> high;
    int count=0;
    for (int i=low; i<high; ++i) {
        string current = to_string(i);
        bool isPal = true;
        for (int j=0; j<ceil(current.length()/2.0); ++j) {
            if ((current[j] == '0' && current[current.length()-j-1] == '0') || (current[j] == '1' && current[current.length()-j-1] == '1') || (current[j] == '8' && current[current.length()-j-1] == '8') || (current[j] == '6' && current[current.length()-j-1] == '9') || (current[j] == '9' && current[current.length()-j-1] == '6')) {
                continue;
            } else {
                isPal = false;
                break;
            }
        }
        if (isPal) {
            ++count;
        }
    }
    cout << count << "\n";
    return 0;
}