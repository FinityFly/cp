#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n, k, worst[101];
ll score[101];
vector<pll> lb;
vector<int> top;

bool srt(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (a.second > b.second);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        lb.clear();
        top.clear();
        for (int j = 0; j < n; ++j) {
            int s; cin >> s;
            score[j] += s;
            lb.push_back({j, score[j]});
        }
        sort(lb.begin(), lb.end(), srt);
        int cur=INT_MAX, place;
        for (int j = 0; j < n; ++j) {
            if (lb[j].second < cur) {
                cur = lb[j].second;
                worst[lb[j].first] = max(worst[lb[j].first], j+1);
                place = j+1;
            } else if (lb[j].second == cur)
                worst[lb[j].first] = max(worst[lb[j].first], place);
            if (place == 1) top.push_back(lb[j].first);
        }
    }
    sort(top.begin(), top.end());
    for (int i = 0; i < top.size(); ++i) {
        cout << "Yodeller " << top[i]+1 << " is the TopYodeller: score " << score[top[i]] << ", worst rank " << worst[top[i]] << "\n";
    }
    return 0;
}