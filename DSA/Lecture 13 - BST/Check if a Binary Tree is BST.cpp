#include <iostream>
#include <climits>
#include "BinaryTreeNode.h"
#include "BinaryTreeInputOutput.h"

using namespace std;

 /*
bool isBST(BinaryTreeNode<int> *root) {
  // MY APPROACH O(N * H)
  if(root == NULL){
        return true;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        return true;
    }
    
    if(root -> left != NULL && root -> left -> data >= root -> data){
        return false;
    }
    
    if(root -> right != NULL && root -> right -> data < root -> data){
        return false;
    }
    
    bool leftAns = true;
    
    if(root -> left != NULL){
        leftAns = isBST(root -> left);
    }
    
    bool rightAns = true;
    
    if(root -> right != NULL){
        rightAns = isBST(root -> right);
    }
    
    return leftAns && rightAns;
 }
    */
// More Efficient Approach

bool isBSThelper(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    return isBSThelper(root->left, min, root->data - 1) &&
           isBSThelper(root->right, root->data, max);
}

bool isBST(BinaryTreeNode<int> *root) {
    return isBSThelper(root, INT_MIN, INT_MAX);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
