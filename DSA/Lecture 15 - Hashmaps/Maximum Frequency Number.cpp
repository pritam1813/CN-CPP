#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> myMap;
    int maxFrequency = 0;
    int maxIndex = 0;
    
    for(int i = n - 1; i >= 0; i--){
    	if(myMap.count(arr[i]) == 0){
    		myMap[arr[i]] = 1;
    	}
    	else{
    		myMap[arr[i]]++;

            if(maxFrequency <= myMap[arr[i]]){
                maxFrequency = myMap[arr[i]];
                maxIndex = i;
            }
    	}
    }
    
    return arr[maxIndex];
}

int main(){
	int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
