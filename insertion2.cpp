#include <iostream>
#include <vector>

using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int i, stored, shifts=0;
    for(int a=1;a<n;++a){
        if(arr[a-1] > arr[a]){
            stored = arr[a];
            i = a-1;
            while(arr[i] > stored){
                arr[i+1] = arr[i];
                shifts++;
                i--;
            }
            arr[i+1] = stored;
        }
        for(int j=0;j<n;++j){
            cout << arr[j] << " ";
        }
        cout << "\n" << shifts;
    }
}

int main()
{
    int ar[] = {2, 1, 3, 1, 2};
    vector<int> arr(ar, ar + sizeof(ar)/sizeof(ar[0]));
    int n = arr.size();
    insertionSort1(n, arr);
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
