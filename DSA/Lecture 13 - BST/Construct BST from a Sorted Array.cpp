#include <iostream>
#include "BinaryTreeInputOutput.h"

using namespace std;

BinaryTreeNode<int>* helper(int *arr, int si, int ei){
	if(si > ei){
		return NULL;
	}

	int mid = (si + ei)/2;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);

	BinaryTreeNode<int>* leftchild = helper(arr,si,mid-1);
	BinaryTreeNode<int>* rightchild = helper(arr,mid+1,ei);

	root -> left = leftchild;
	root -> right = rightchild;

	return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
	return helper(input,0,n-1);
}

int main()
{
	int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
	return 0;
}
