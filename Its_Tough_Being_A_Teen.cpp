#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
/*

*/

int ind[7] = {1, 0, 0, 2, 1, 0, 1};
vector<pair<int, int>> con = {{0, 6}, {0, 3}, {1, 0}, {2, 3}, {2, 4}};
vector<int> arr[7] = {{3, 6}, {0}, {3, 4}, {}, {}, {}, {}};
queue<int> q;
vector<int> output;

void sortQueue() {
    vector<int> v;
    while(!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i) {
        q.push(v[i]);
    }
}

void printInd() {
    cout << "\nIND:\n";
    for (int i = 0; i < 7; ++i) {
        cout << ind[i] << " ";
    }
    cout << "\n";
}

void printArr() {
    cout << "\nARR:\n";
    for (int i = 0; i < 7; ++i) {
        cout << "i: " << i << " | ";
        for (int j = 0; j < arr[i].size(); ++j) {
            cout << arr[i][j] << " ";
        }
        if (arr[i].size() == 0) {
            cout << "NONE";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printQueue(queue<int> q) {
    cout << "\nQUEUE:\n";
    while (!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        con.push_back({a-1, b-1});
        arr[a-1].push_back(b-1);
        ++ind[b-1];
    }
    for (int i = 0; i < 7; ++i) {
        if (ind[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        // printInd();
        // printArr();
        // printQueue(q);
        sortQueue();
        int a = q.front();
        q.pop();
        output.push_back(a+1);
        for (int i = 0; i < arr[a].size(); ++i) {
            --ind[arr[a][i]];
            if (ind[arr[a][i]] == 0)
                q.push(arr[a][i]);
        }
    }
    if (output.size() < 7) {
        cout << "Cannot complete these tasks. Going to bed.\n";
    } else {
        for (int i = 0; i < 7; ++i) {
            cout << output[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}