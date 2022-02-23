#include <iostream>
#include "BinaryTreeInputOutput.h"

using namespace std;

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL){
        return NULL;
    }

    if(root -> data == data){
    	vector<int>* ans = new vector<int>();
    	ans -> push_back(root -> data);
    	return ans;
    }

    if(root -> data > data){
    	vector<int>* leftSub = getPath(root -> left,data);
    	if(leftSub != NULL){
    		leftSub -> push_back(root -> data);
    	}
    	return leftSub;
    }

    if(root -> data < data){
    	vector<int>* rightSub = getPath(root -> right,data);
    	if(rightSub != NULL){
    		rightSub -> push_back(root -> data);
    	}
    	return rightSub;
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}
