#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
/*

*/
int n;
int arr[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int index = ceil(n/2.0)-1;
    for(int i=0;i<n/2.0;++i){
        if (n%2==1 && i==floor(n/2.0)) {
            cout << arr[index-i];
        } else {
            cout << arr[index-i] << " " << arr[index+1+i] << " ";
        }
    }
    return 0;
}