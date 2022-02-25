#include <iostream>
#include "BinaryTreeInputOutput.h"

using namespace std;


int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root == NULL){
    	return -1;
    }

    if(root -> data == a){
    	return a;
    }

    if(root -> data == b){
    	return b;
    }

    int leftAns = getLCA(root -> left,a,b);
    int rightAns = getLCA(root -> right,a,b);

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
