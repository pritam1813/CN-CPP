#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

TreeNode<int>* takeInput(){
    int i = 0;
    cout <<"Enter data : ";
    cin >> i;
    TreeNode<int>* root = new TreeNode<int>(i);

    cout << "Enter Number of Children Node of " << i <<endl;
    cin >> i;
    for(int j = 0; j < i; j++){
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root){
        if(root == NULL){
            return;
        }

        cout << root -> data << " : ";

        for(int i = 0; i < root -> children.size(); i++){
            cout << root -> children[i] -> data << ", ";
        }
        cout << endl;

        for(int i = 0; i < root -> children.size(); i++){
            printTree(root -> children[i]);
        } 
        return;
}

int main(){
    
    TreeNode<int> *root = takeInput();
    printTree(root);
}
