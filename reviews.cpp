#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int m, n, pho[1000];
vector<int> adj[1000];
queue<int> q;
bool v[1000];
int d[1000];

void explore(int x, vector<int> t){
    //    for(auto u : adj[x]){
    for(int u=0;u<adj[x].size();++u){
        if(find(t.begin(), t.end(), u) != t.end()) continue;
        t.push_back(u);
        explore(u, t);
    }
}

int dfs(int x){
    vector<int> t;
    t.push_back(x);
    explore(x, t);
    for(int i=0;i<t.size();++i){
        cout << t[i] << " ";
    }
    return t.size();
}

//void bfs(int x){
//    v[x]=true;
//    d[x]=0;
//    q.push(x);
//    while(!q.empty()){
//        int s=q.front(); q.pop();
//        cout << s << " ";
//        for(auto u : adj[s]){
//            if(v[u]) continue;
//            v[u] = true;
//            d[u] = d[s]+1;
//            q.push(u);
//        }
//    }
//}

bool findElement(vector<int> arr[], int element){
    for(int i=0;i<m-1;++i){
        if(arr.at(i) == element)
            return true;
    }
    return false;
}

void solve(){
    int ans=10000, temp;
    for(int i=0;i<n;++i){
        temp = dfs(pho[i]);
        if(temp<ans)
            ans = temp;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<n;++i){
        cin >> pho[i];
    }
    int a, b;
    vector<int> temp;
    for(int j=0;j<m-1;++j){
        cin >> a >> b;
        bool found = findElement(adj, a);
        if(!found){
            temp.push_back(b);
//            adj.insert(adj[a], temp.begin(), temp.end());
            adj[a] = temp;
        } else {
            adj[a].push_back(b);
        }
    }
    for(int i=0;i<m-1;++i){
        for(int j=0;j<adj[m-1].size();++j){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    solve();
    return 0;
}