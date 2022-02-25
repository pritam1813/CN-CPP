#include <iostream>
#include "BinaryTreeInputOutput.h"

using namespace std;


int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root == NULL){
    	return -1;
    }

    if(root -> data == val1){
    	return val1;
    }

    if(root -> data == val2){
    	return val2;
    }

    int mn = min(val1,val2);
    int mx = max(val1,val2);
    int leftAns;
    int rightAns;

    if(mn < root -> data && mx > root -> data){
        leftAns = getLCA(root -> left,val1,val2);
        rightAns = getLCA(root -> left,val1,val2);
    }
    else if(mn < root -> data && mx < root -> data){
        return getLCA(root -> left , val1, val2);
    }
    else{
        return getLCA(root -> right, val1, val2);
    }
    
    
    if(leftAns != -1 && rightAns != -1){
    	return root -> data;
    }
    else if(leftAns != -1){
    	return leftAns;
    }
    else if(rightAns != -1){
    	return rightAns;
    }
    else{
    	return -1;
    }

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}
