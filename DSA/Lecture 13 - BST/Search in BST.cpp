



bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root == NULL){
        return false;
    }
    
    if(root -> data == k){
        return true;
    }
    return (k < root -> data ? searchInBST(root -> left,k) : searchInBST(root -> right,k));
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    delete root;
}
