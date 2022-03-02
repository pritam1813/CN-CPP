#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void buildHeap(int arr[], int n, int childIndex){
    if(childIndex > (n - 1)){
        return;
    }
    int tempIndex = childIndex;

    
    while(tempIndex > 0){
        int parentIndex = (tempIndex - 1) / 2;

        if(arr[tempIndex] < arr[parentIndex]){
            swap(arr[tempIndex], arr[parentIndex]);
        }
        else{
            break;
        }
        tempIndex = parentIndex;
    }
    
    buildHeap(arr,n,childIndex + 1);
}

void minHeapSort(int arr[], int n){
    if(n == 0){
        return;
    }

    swap(arr[0],arr[n - 1]);
    int parentIndex = 0;
    int leftChildIndex = (2 * parentIndex) + 1;
    int rightChildIndex = (2 * parentIndex) + 2;

    while(leftChildIndex < n - 1){
        int minIndex = parentIndex;

        if(arr[minIndex] > arr[leftChildIndex]){
            minIndex = leftChildIndex;
        }
        if(rightChildIndex < n - 1){
            if(arr[minIndex] > arr[rightChildIndex]){
                minIndex = rightChildIndex;
            }
        }
        if(minIndex == parentIndex){
            break;
        }

        swap(arr[minIndex], arr[parentIndex]);
        parentIndex = minIndex;
        leftChildIndex = (2 * parentIndex) + 1;
        rightChildIndex = (2 * parentIndex) + 2;
    }
    minHeapSort(arr, n - 1);
}


void heapSort(int arr[], int n) {
    // Write your code
    buildHeap(arr,n,1);
    minHeapSort(arr,n);
}


int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
