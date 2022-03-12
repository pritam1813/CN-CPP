#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
    // Write your code here
    unordered_map<int,int> myMap;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        myMap[arr[i]]++;
        if(myMap.count(-arr[i]) != 0){
            count += myMap[-arr[i]];
            if(arr[i] == -arr[i]){
                count--;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);
    delete[] arr;
}
