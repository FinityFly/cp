#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*

*/
bool eventDone[10000];
int eventTime[10000];
int sum = 0;
vector<int> preReq[10000];

int complete(int eventNum) {
    if (!eventDone[eventNum]) {
        bool qualified = true;
        int time = 0;
        for (int i = 0; i < preReq[eventNum].size(); ++i) {
            if (eventDone[preReq[eventNum][i]-1] == false) {
                eventDone[eventNum] = true;
                qualified = false;
                time = max(time, complete(preReq[eventNum][i]-1));
            }
        }
        if (qualified) {
            eventDone[eventNum] = true;
            return eventTime[eventNum];
        } else {
            return time + eventTime[eventNum];
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    fill(eventDone, eventDone + n, false);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> eventTime[i] >> a;
        for (int j = 0; j < a; ++j) {
            int b;
            cin >> b;
            preReq[i].push_back(b);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (preReq[i].size() == 0) {
            sum = max(sum, complete(i));
        } else {
            sum += complete(i);
        }
    }
    cout << sum << "\n";
    return 0;
}