#include <iostream>
#include "BinaryTreeInputOutput.h"

using namespace std;

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
    	return;
    }

    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root -> data);

    if(root -> left == NULL){
    	root -> left = newNode;
    }
    else{
    	BinaryTreeNode<int>* temp = root -> left;
    	root -> left = newNode;
    	newNode -> left = temp;
    }

    insertDuplicateNode(root -> left -> left);
    insertDuplicateNode(root -> right);

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    delete root;
}
