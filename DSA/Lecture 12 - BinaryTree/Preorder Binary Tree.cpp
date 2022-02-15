#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
    cout << root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    preOrder(root);
}
