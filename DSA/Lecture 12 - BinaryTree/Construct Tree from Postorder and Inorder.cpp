#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

int searchRoot(int *inorder,int inLength, int rootdata){
    
    if(inorder[inLength - 1] == rootdata){
        return inLength - 1;
    }
    return searchRoot(inorder, inLength - 1, rootdata);
}

BinaryTreeNode<int>* helper(int *postorder,int postStartIndex, int postEndIndex, int *inorder, int inStartIndex, int inEndIndex){
    if(inStartIndex > inEndIndex){
        return NULL;
    }

    int inRootIndex = searchRoot(inorder, inEndIndex + 1, postorder[postEndIndex]);
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(inorder[inRootIndex]);
    
    int inLeftStart = inStartIndex;
    int inLeftEnd = inRootIndex - 1;
    int postLeftStart = postStartIndex;
    int postLeftEnd = postLeftStart + (inLeftEnd - inLeftStart);

    int inRightStart = inRootIndex + 1;
    int inRightEnd = inEndIndex;
    int postRightStart = postLeftEnd + 1;
    int postRightEnd = postEndIndex - 1;

    BinaryTreeNode<int>* leftchild = helper(postorder,postLeftStart,postLeftEnd,inorder,inLeftStart,inLeftEnd);
    BinaryTreeNode<int>* rightchild = helper(postorder,postRightStart,postRightEnd,inorder,inRightStart,inRightEnd);

    root -> left = leftchild;
    root -> right = rightchild;
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder, 0 , postLength - 1, inorder, 0, inLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
