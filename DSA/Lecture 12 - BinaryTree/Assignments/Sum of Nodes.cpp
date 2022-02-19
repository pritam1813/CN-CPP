#include <iostream>
#include "LevelWiseInputOutput.h"

using namespace std;

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    
    return root -> data + getSum(root -> left) + getSum(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);
}
