#include <iostream>
#include "BinaryTreeInputOutput.h"
#include "Node.h"

using namespace std;

pair<Node<int>*,Node<int>*> LLheadTail(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<Node<int>*,Node<int>*> p1;
		p1.first = NULL;
		p1.second = NULL;
		return p1;
	}

	if(root -> left == NULL && root -> right == NULL){
		pair<Node<int>*,Node<int>*> p1;
		p1.first = new Node<int>(root -> data);
		p1.second = p1.first;
		return p1;
	}

	pair<Node<int>*,Node<int>*> leftSub = LLheadTail(root -> left);
	pair<Node<int>*,Node<int>*> rightSub = LLheadTail(root -> right);
	Node<int>* head = new Node<int>(root -> data);

	head -> next = rightSub.first;

	pair<Node<int>*,Node<int>*> Ans;

	if(leftSub.first != NULL){
		Ans.first = leftSub.first;
	}

	if(leftSub.second != NULL){
		leftSub.second -> next = head;
	}
	else{
		Ans.first = head;
	}
	
	if(rightSub.second != NULL){
		Ans.second = rightSub.second;
	}
	else{
		Ans.second = head;
	}

	return Ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	return LLheadTail(root).first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
