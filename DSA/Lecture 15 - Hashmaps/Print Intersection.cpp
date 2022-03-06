#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> myMap;
    sort(arr1,arr1 + n);
  
    for(int i = 0; i < m; i++){
        if(myMap.count(arr2[i]) == 0){
            myMap[arr2[i]] = 1;
        }
        else{
            myMap[arr2[i]]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(myMap[arr1[i]] > 0){
            cout << arr1[i] << endl;
            myMap[arr1[i]]--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
