#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

void swapTree(BinaryTreeNode<int>* &left, BinaryTreeNode<int>* &right){
    
    BinaryTreeNode<int>* temp = right;
        right = left;
        left = temp;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    swapTree(root -> left, root -> right);
    
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
