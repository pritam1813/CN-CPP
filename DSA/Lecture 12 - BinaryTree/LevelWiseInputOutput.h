#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int>* takeInputLW(){
    int rootData;
    cout <<"Enter Root Data : ";
    cin >> rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    queue<BinaryTreeNode<int>*> bt;

    bt.push(root);

    while (bt.size() != 0)
    {
        BinaryTreeNode<int>* front = bt.front();
        bt.pop();

        int leftChild;
        cout<<"Enter Left child of " << front -> data <<" : ";
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* leftC = new BinaryTreeNode<int>(leftChild);
            front -> left = leftC;
            bt.push(leftC);
        }

        int rightChild;
        cout<<"Enter Right child of " << front -> data <<" : ";
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* rightC = new BinaryTreeNode<int>(rightChild);
            front -> right = rightC;
            bt.push(rightC);
        }
    }
    return root;
}


void printTree(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> bt;
    bt.push(root);
    
    while (!bt.empty())
    {
        cout << bt.front() -> data << ":";
        if(bt.front() -> left != NULL){
            cout << "L:" << bt.front() -> left -> data <<",";
            bt.push(bt.front() -> left);
        }
        else{
            cout << "L:-1" <<",";
        }
        

        if(bt.front() -> right != NULL){
            cout << "R:" << bt.front() -> right -> data;
            bt.push(bt.front() -> right);
        }
        else{
             cout << "R:-1";
        }

        cout << endl;

        bt.pop();
    }
    
}
