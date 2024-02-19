#include <bits/stdc++.h>
using namespace std;

/*
INPUT:

 */

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string key, msg;
    cin >> key;
    cin.ignore();
    getline(cin, msg);
    int index = 0;
    for (int i = 0; i < msg.length(); ++i) {
        if ((int) msg[i] >= 65 && (int) msg[i] <= 90) {
            msg[index] = (char) msg[i];
            ++index;
        }
    }
    msg.erase(index, string::npos);
    index = 0;
    string output;
    for (int i = 0; i < msg.length(); ++i) {
        int pos = (char) ((int) msg[i] + ((int) key[index] - 65));
        if (pos > 90) {
            pos = 65 + (pos - 90 - 1);
        }
        output += (char) pos;
        ++index;
        if (index >= key.length()) {
            index = 0;
        }
    }
    cout << output << "\n";
    return 0;
}