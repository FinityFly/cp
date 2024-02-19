#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/

int pairExists(vector<pair<int, int>> arr, int id) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].first == id) {
            return i;
        }
    }
    return -1;
}

bool sortsec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

bool sortfir(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.first < b.first);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr; // id, freq
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (pairExists(arr, a) != -1) {
            arr[pairExists(arr, a)].second++;
        } else {
            arr.push_back(make_pair(a, 1));
        }
    }
    sort(arr.begin(), arr.end(), sortsec);
    cout << '\n';
    int highestid = arr[arr.size()-1].second;
    int nexthighid = -1;
    for (int i = arr.size()-1; i >= 0; --i) {
        if (arr[i].second != highestid) {
            nexthighid = arr[i].second;
            break;
        }
    }
    if (nexthighid == -1) {
        nexthighid = highestid;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].second < nexthighid) {
            arr.erase(arr.begin() + i);
            --i;
        }
    }
    sort(arr.begin(), arr.end(), sortfir);
    cout << abs(arr[0].first - arr[arr.size()-1].first) << "\n";
    return 0;
}