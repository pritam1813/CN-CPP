#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

int searchRoot(int *inorder,int inLength, int rootdata){
    
    if(inorder[inLength - 1] == rootdata){
        return inLength - 1;
    }
    return searchRoot(inorder, inLength - 1, rootdata);
}

BinaryTreeNode<int>* helper(int *preorder,int preStartIndex, int preEndIndex, int *inorder, int inStartIndex, int inEndIndex){
    
    int inRootIndex = searchRoot(inorder, inEndIndex + 1, preorder[preStartIndex]);
    BinaryTreeNode<int>* newRoot = new BinaryTreeNode<int>(inorder[inRootIndex]);

    int inLeftStart = inStartIndex;
    int inLeftEnd = inRootIndex - 1;
    
    int preLeftStart = preStartIndex + 1;
    int preLeftEnd = preLeftStart + (inLeftEnd - inLeftStart);

    BinaryTreeNode<int>* leftchild = NULL;
    if(inLeftStart <= inLeftEnd){
        leftchild = helper(preorder,preLeftStart,preLeftEnd,inorder,inLeftStart,inLeftEnd);
    }

    int inRightStart = inRootIndex + 1;
    int inRightEnd = inEndIndex;
    
    int preRightStart = preLeftEnd + 1;
    int preRightEnd = preEndIndex;

    BinaryTreeNode<int>* rightchild = NULL;
    if(preRightStart <= preRightEnd){
        rightchild = helper(preorder,preRightStart,preRightEnd,inorder,inRightStart,inRightEnd);
    }

    newRoot -> left = leftchild;
    newRoot -> right = rightchild;

    return newRoot;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root = helper(preorder,0,preLength - 1, inorder, 0, inLength - 1);

    return root;
    
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
