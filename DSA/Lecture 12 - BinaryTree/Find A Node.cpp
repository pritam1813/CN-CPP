#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;


bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
    
}

// Sample Tree
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){
    BinaryTreeNode<int>* root = takeInputLW();
    cout <<endl;
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}
