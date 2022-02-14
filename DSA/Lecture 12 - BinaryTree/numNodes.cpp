#include <iostream>
#include "LevelWiseInputOutput.h"
using namespace std;

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root -> left) + numNodes(root -> right);
}

// Sample Tree
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = takeInputLW();
    cout <<endl;

    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* right = new BinaryTreeNode<int>(3);

    root -> left = left;
    root -> right = right;*/

    printTree(root);
    cout << endl;
    cout << "Number of node : " << numNodes(root);
    cout << endl;
}
