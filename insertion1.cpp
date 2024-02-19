#include <iostream>
#include <vector>

using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int i = n-1, stored = arr[n-1];
    while(arr[i-1] > stored){
        arr[i] = arr[i-1];
        i--;
        for(int j=0;j<n;++j){
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
    arr[i] = stored;
    for(int j=0;j<n;++j){
        cout << arr[j] << " ";
    }
}

int main()
{
    int ar[] = {2, 4, 6, 8, 3};
    vector<int> arr(ar, ar + sizeof(ar)/sizeof(ar[0]));
    int n = arr.size();
    insertionSort1(n, arr);
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
