#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<int,bool> helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    
    pair<int,bool> leftAns = helper(root -> left);
    pair<int,bool> rightAns = helper(root -> right);
    
    pair<int,bool> ans;
    
    ans.first = 1 + max(leftAns.first,rightAns.first);
    
    if(leftAns.second && rightAns.second){
        if(abs(leftAns.first - rightAns.first) <= 1){
            ans.second = true;
        }
    }
    else{
        ans.second = false;
    }
    
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    pair<int,bool> ans = helper(root);
    return ans.second;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}
