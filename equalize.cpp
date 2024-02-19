#include <iostream>
#include <vector>
#include <map>

using namespace std;

int equalizeArray(vector<int> arr) {
    int output = 0;
    int n = arr.size();
    map<int, int> numbers;
    for(int i=0;i<n;++i){
        if(numbers.find(arr[i])!=numbers.end()){
            numbers[arr[i]] += 1;
        }else{
            numbers.insert(pair<int, int>(arr[i], 1));
        }
    }
    // for(map<int, int>::const_iterator it = numbers.begin();it!=numbers.end();++it){
    //     cout << "m[" << it->first << "] = " << it->second << "\n";
    // }
    int longest = 0;
    int index;
    for(int j=0;j<numbers.size();++j){
        if(numbers[j]>longest){
            longest = numbers[j];
            index = j;
        }
    }
    for(int k=0;k<n;++k){
        if(arr[k]!=index){
            output++;
        }
    }
    return output;
}

int main()
{
    int arr[] = {3, 3, 2, 1, 3};
    vector<int> ar(arr, arr + sizeof(arr)/sizeof(arr[0]));
    int result = equalizeArray(ar);
    cout << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
