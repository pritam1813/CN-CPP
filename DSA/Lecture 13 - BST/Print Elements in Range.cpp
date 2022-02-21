#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTreeInputOutput.h"

using namespace std;

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(root == NULL){
        return;
    }
    
    if(root -> data > k2){
        elementsInRangeK1K2(root -> left,k1,k2);
    }
    
    if(root -> data < k1){
        elementsInRangeK1K2(root -> right,k1,k2);
    }
    
    if(root -> data >= k1 && root -> data <= k2){
        elementsInRangeK1K2(root -> left,k1,k2);
        cout << root -> data << " ";
        elementsInRangeK1K2(root -> right,k1,k2);
    }
    return;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}
