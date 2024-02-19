#include <iostream>
#include <vector>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
    int output=0;
    vector<int> pairs;
    sort(ar.begin(),ar.end());
    pairs.push_back(ar[0]);
    for(int i=1;i<ar.size();++i){
        vector<int>::iterator it = find(pairs.begin(), pairs.end(), ar[i]);
        // cout << "\n" << i << ":\n";
        // cout << it - pairs.begin() << "\n";
        if(it==pairs.end()){
            pairs.push_back(ar[i]);
        }else{
            output += 1;
            int index = it - pairs.begin();
            pairs.erase(pairs.begin() + index);
        }
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 1, 2, 1, 3, 2};
    vector<int> ar(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int n = ar.size();
    int result = sockMerchant(n, ar);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
