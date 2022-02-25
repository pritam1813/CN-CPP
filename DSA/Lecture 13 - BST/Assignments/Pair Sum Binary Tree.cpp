#include <iostream>
#include "BinaryTreeInputOutput.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* BTtoArray(BinaryTreeNode<int> *root){
	if(root == NULL){
		return NULL;
	}
	vector<int>* leftAns = BTtoArray(root -> left);
	vector<int>* rightAns = BTtoArray(root -> right);
	vector<int>* ans = new vector<int>();

	if(leftAns == NULL && rightAns == NULL){
		ans -> push_back(root -> data);
	}
	else if(rightAns == NULL){
		leftAns -> push_back(root -> data);
		ans = leftAns;
	}
	else if(leftAns == NULL){
		rightAns -> push_back(root -> data);
		ans = rightAns;
	}
	else{
		leftAns -> push_back(root -> data);
		for(int i = 0; i < rightAns -> size(); i++){
			leftAns -> push_back(rightAns -> at(i));
		}
		ans = leftAns;
	}
	return ans;
}

/*-------DON'T FORGET TO INCLUDE ALGORITHM AND VERCTOR FILE-------*/

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int>* arr = BTtoArray(root);
	sort(arr -> begin(), arr -> end());

    int i = 0;
    int j = arr -> size() - 1;
    while(i < j){
    	int currentSum = arr -> at(i) + arr -> at(j);

    	if(currentSum == sum){
    		cout << arr -> at(i) <<" ";
    		cout << arr -> at(j) << endl;
    		i++;
    		j--;
    	}
    	else if(currentSum > sum){
    		j--;
    	}
    	else{
    		i++;
    	}
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
