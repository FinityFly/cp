#include <iostream>
#include <vector>

using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int output = -1;
    int m = keyboards.size();
    int n = drives.size();
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(keyboards[i]+drives[j] > output && keyboards[i]+drives[j] <= b){
                output = keyboards[i]+drives[j];
                if(keyboards[i]+drives[j] == b){
                    return b;
                }
            }
        }
    }
    return output;
}

int main()
{
    int arr1[] = {3, 1};
    vector<int> keyboards(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = {5, 2, 8};
    vector<int> drives(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    int b = 10;
    int result = getMoneySpent(keyboards, drives, b);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }
    return 0;
}
