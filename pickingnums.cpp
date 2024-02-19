#include <iostream>
#include <vector>

using namespace std;

int pickingNumbers(vector<int> a) {
    int output = 0;
    //split arrays to sub arrays (in a 2d vector)
    vector< vector<int> > splitarr;
    vector<int> sub;
    int temp;
    for(int i=0;i<a.size();++i){
        temp = a[i];
        if(temp==a[i+1]){

        }
    }
    //which arrays are adjacent
    //compare lengths of adjacent arrays
    return output;
}

int main()
{
    int arr[] = {4, 6, 5, 3, 3, 1};
    vector<int> a(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int result = pickingNumbers(a);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int a[102];
// int main(){
//     int n, t;
//     scanf("%d",&n);
//     for(int i = 0; i < n; i++){
//         scanf("%d",&t);
//         a[t]++;
//     }
//     int ma = 0;
//     for(int i = 0; i < 100; i++){
//         if(a[i]+a[i+1]>ma){
//             ma = a[i]+a[i+1];
//         }
//     }
//     printf("%d",ma);
// }