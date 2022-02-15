#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return;
    }

    if(root -> left != NULL && root -> right != NULL){
        //swap(root -> left -> data,root -> right -> data );
        BinaryTreeNode<int>* temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;
    }
    
    if(root -> right != NULL && root -> left == NULL){
        BinaryTreeNode<int>* temp = root -> right; 
        root -> left = temp;
        root -> right = NULL;
    }
    
    if(root -> left != NULL && root -> right == NULL){
        BinaryTreeNode<int>* temp = root -> left; 
        root -> right = temp;
        root -> left = NULL;
    }
    
    mirrorBinaryTree(root -> right);
    mirrorBinaryTree(root -> left);
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
int main() {
    BinaryTreeNode<int> *root = takeInputLW();
    mirrorBinaryTree(root);
    printLevelATNewLine(root);
}
