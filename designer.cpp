#include <iostream>
#include <vector>

using namespace std;

int designerPdfViewer(vector<int> h, string word) {
    int output = 0;
    vector<int> lengths;
    for(int i=0;i<word.length();++i){
        int index = word[i] - 97;
        lengths.push_back(h[index]);
    }
    sort(lengths.begin(), lengths.end());
    int height = lengths.back();
    output = height * word.length();
    return output;
}

int main()
{
    int arr[] = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    vector<int> h(arr, arr + sizeof(arr)/sizeof(arr[0]));
    string word = "abc";
    int result = designerPdfViewer(h, word);
    cout << "\n" << result;
    // for(int i=0;i<result.size();++i){
    //   cout << result[i] << " ";
    // }

    return 0;
}
