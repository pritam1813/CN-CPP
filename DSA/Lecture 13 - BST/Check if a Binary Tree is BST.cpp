#include <iostream>
#include <climits>
#include "BinaryTreeNode.h"
#include "BinaryTreeInputOutput.h"

using namespace std;

/*
// Approach 1 O(n * h)

int minimum(BinaryTreeNode<int> *root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root -> data,min(minimum(root -> left),minimum(root -> right)));
}

int maximum(BinaryTreeNode<int> *root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root -> data,max(maximum(root -> left),maximum(root -> right)));
}
bool isBST(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return true;
    }
    
    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);

    return (root -> data > leftMax) && (root -> data <= rightMin) && isBST(root -> left) && isBST(root -> right); 
}
*/

/*
// Approach 2 O(n)

pair<pair<int,int>,bool> helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair<pair<int,int>,bool> p1;
        pair<int,int> p2;
        p2.first = INT_MAX;  //This member is denoting Minimum value
        p2.second = INT_MIN;  ////This member is denoting Maximum value
        p1.first = p2;
        p1.second = true;
        return p1;
    }
    pair<pair<int,int>,bool> leftAns = helper(root -> left);
    pair<pair<int,int>,bool> rightAns = helper(root -> right);

    pair<pair<int,int>,bool> ans;
    ans.first.first = min(root -> data,min(leftAns.first.first, rightAns.first.first));          //Overall minimum
    ans.first.second = max(root -> data,max(leftAns.first.second, rightAns.first.second));       //Overall maximum

          // overall isBST by comparing rootData with leftMax and rightMin and also checking left isBST && right isBST
          
    ans.second = (root -> data > leftAns.first.second) && (root -> data <= rightAns.first.first) && leftAns.second && rightAns.second;
    return ans;
}

bool isBST(BinaryTreeNode<int> *root) {
    pair<pair<int,int>,bool> Ans = helper(root);
    return Ans.second;
}
*/


// Approach 3 pushing down the constraints O(n)

bool helper(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL){
        return true;
    }
    // Considering rootData is between -infinity to +infinity for first time
 
    if(root -> data < min || root -> data > max){
        return false;
    }
 
    // Changing cnstraint while calling left root->Left Data will be greater than -infinity but less than root Data
    // Similarly for calling right , root -> right data is greater than equal to root data but less than +infinity  
 
    return helper(root -> left,min,root -> data - 1) && helper(root -> right,root -> data,max);
}

bool isBST(BinaryTreeNode<int> *root) {
    return helper(root, INT_MIN, INT_MAX);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
