#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data <<" ";
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    postOrder(root);
}
