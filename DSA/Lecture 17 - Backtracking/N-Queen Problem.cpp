#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int arr[11][11];

bool isPossible(int n, int row, int col){

    // Checking Column Wise from Bottom
    for(int i = row - 1; i >= 0; i--){
        if(arr[i][col] == 1){
            return false;
        }
    }

    // Checking Upper Left Diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
        if(arr[i][j] == 1){
            return false;
        }
    }

    // Checking Upper-right Diagonal
    for (int i = row - 1, j = col + 1; i >=0 && j < n; i--,j++)
    {
        if(arr[i][j] == 1){
            return false;
        }
    }

    return true;
}

void nqueenHelper(int row, int n){
    if(row == n){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int j = 0; j < n; j++){
        if(isPossible(n,row,j)){
            arr[row][j] = 1;
            nqueenHelper(row + 1, n);
            arr[row][j] = 0;
        }
    }
    return;
}

void placeNqueen(int n){
    memset(arr,0,11*11*sizeof(int));
    nqueenHelper(0,n);
}

int main(){
    
    // write your code here
    int N;
    cin >> N;

    placeNqueen(N);
}