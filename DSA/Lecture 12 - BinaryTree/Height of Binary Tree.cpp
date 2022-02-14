#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL){
        return 0;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        return 1;
    }
    
    return 1 + max(height(root -> left),height(root -> right));
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root);
}
