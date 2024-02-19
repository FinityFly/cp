#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
/*

*/
int t, g, cnt=0;
vector<int> points = {0, 0, 0, 0, 0};
vector<pair<int, int>> games;
vector<vector<int>> scores;

void removeGame(pair<int, int> p) {
    for (int i = 0; i < games.size(); ++i) {
        if (p.first == games[i].first && p.second == games[i].second)
            games.erase(games.begin() + i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    games.push_back(mp(1, 2));
    games.push_back(mp(1, 3));
    games.push_back(mp(1, 4));
    games.push_back(mp(2, 3));
    games.push_back(mp(2, 4));
    games.push_back(mp(3, 4));
    cin >> t >> g;
    for (int i = 0; i < g; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x > y)
            points[a] += 3;
        else if (x < y)
            points[b] += 3;
        else {
            ++points[a];
            ++points[b];
        }
        removeGame(mp(a, b));
    }
    scores.push_back(points);
    for (int i = 0; i < 6-g; ++i) {
        int a = games[0].first;
        int b = games[0].second;
        games.erase(games.begin());
        vector<vector<int>> temp;
        for (int j = 0; j < scores.size(); ++j) {
            vector<int> foo(5);
            for (int k = 1; k < 5; ++k)
                foo[k] = scores[j][k];
            foo[a]+=3; temp.push_back(foo); foo[a]-=3;
            foo[b]+=3; temp.push_back(foo); foo[b]-=3;
            ++foo[a]; ++foo[b];
            temp.push_back(foo);
        }
        scores.clear();
        for (int j = 0; j < temp.size(); ++j)
            scores.push_back(temp[j]);
    }
    for (int i = 0; i < scores.size(); ++i) {
        int maxValue=-1, maxIndex=0;
        for (int j = 1; j < 5; ++j) {
            if (scores[i][j] > maxValue) {
                maxValue = scores[i][j];
                maxIndex = j;
            }
        }
        if (maxIndex == t) ++cnt;
    }
    cout << cnt << "\n";
    return 0;
}