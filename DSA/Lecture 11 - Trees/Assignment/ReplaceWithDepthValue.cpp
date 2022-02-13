#include <iostream>
#include "TreeNode.h"
#include <queue>

using namespace std;

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

void helper(TreeNode<int>* root, int depth){

    if(root -> children.size() == 0){
        root -> data = depth;
        return;
    }
    root -> data = depth;
    depth++;
    for (int i = 0; i < root -> children.size(); i++)
    {
        
        helper(root -> children[i],depth);
    }

    /*for (int i = 0; i < root -> children.size(); i++)
    {
        root -> children[i] -> data = depth;
    }*/

}
  //  1
  ///2 3 4
//4 5

void replaceWithDepthValue(TreeNode<int>* root) {
    if(root ==NULL){
        return;
    }

    //int depth = 0;

    helper(root,0);
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}