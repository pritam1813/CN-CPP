#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
    
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data <= node -> data){
			BinaryTreeNode<int>* ans = insert(node -> left,data);
			node -> left = ans;
			return node;
		}
        else{
			BinaryTreeNode<int>* ans = insert(node -> right,data);
			node -> right = ans;
			return node;
		}
    }
    
    void print(BinaryTreeNode<int>* nodes){
		if(nodes == NULL){
			return;
		}

		cout << nodes -> data << ":";

		if(nodes -> left != NULL){
			cout <<"L:"<< nodes -> left -> data << ",";
		}

		if(nodes -> right != NULL){
			cout <<"R:" << nodes -> right -> data;
		}
		cout << endl;
		print(nodes -> left);
		print(nodes -> right);
		return;
	}
    
    bool search(BinaryTreeNode<int>* node, int data){
        if(node == NULL){
            return false;
        }
        
        if(node -> data == data){
            return true;
        }
        
        if(node -> data < data){
            return search(node -> right, data);
        }
        else{
            return search(node -> left, data);
        }
    }
    
    
    
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data){
        if(node == NULL){
    		return NULL;
    	}
        
        if (data > node->data)
        {
            node->right = remove(node->right,data);
            return node;
        }
    	else if (data < node->data)
        {
            node->left = remove(node->left,data);
            return node;
        }
        else{
            if(node -> left == NULL && node -> right == NULL){
    			delete node;
    			return NULL;
    		}
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right,rightMin);
                return node;
            }
        }
    }
    
    
	public:
    void remove(int data) { 
        // Implement the remove() function 
        root = remove(root,data);
    	return;
    }

    void print() { 
        // Implement the print() function
        print(root);
        return;
    }

    void insert(int data) { 
        // Implement the insert() function
        root = insert(root,data);
        return;
    }

    bool search(int data) {
		// Implement the search() function
        return search(root,data);
    }
};
