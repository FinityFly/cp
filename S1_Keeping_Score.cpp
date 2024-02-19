#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string n;
    int suit = 0, total = 0;
    vector<char> cards[4];
    cin >> n;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == 'C') {
            suit = 0;
        } else if (n[i] == 'D') {
            suit = 1;
        } else if (n[i] == 'H') {
            suit = 2;
        } else if (n[i] == 'S') {
            suit = 3;
        } else {
            cards[suit].push_back(n[i]);
        }
    }
    cout << "Cards Dealt Points\n";
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            cout << "Clubs ";
        } else if (i == 1) {
            cout << "Diamonds ";
        } else if (i == 2) {
            cout << "Hearts ";
        } else {
            cout << "Spades ";
        }
        int suitetotal = 0;
        for (int j = 0; j < cards[i].size(); ++j) {
            cout << cards[i].at(j) << " ";
            if (cards[i].at(j) == 'J') {
                suitetotal += 1;
            } else if (cards[i].at(j) == 'Q') {
                suitetotal += 2;
            } else if (cards[i].at(j) == 'K') {
                suitetotal += 3;
            } else if (cards[i].at(j) == 'A') {
                suitetotal += 4;
            }
        }
        if (cards[i].size() < 3) {
            suitetotal += 3 - cards[i].size();
        }
        cout << suitetotal << "\n";
        total += suitetotal;
    }
    cout << "Total " << total << "\n";
    return 0;
}