#include <iostream>

using namespace std;

struct NodeBst {
	int data;
	int key;
	NodeBst *left;
	NodeBst *right;
};

void inOrder(NodeBst *root) {
	if(root != NULL) {
		inOrder(root -> left);
		cout << root -> data << "(" << root -> key << ")" << endl;
		inOrder(root -> right);
	}
}

NodeBst* insert(NodeBst *&root, int value, int key) {
	NodeBst *aux = root;
	
	NodeBst *newNode = new NodeBst;
	newNode -> data = value;
	newNode -> key = key;
	newNode -> left = NULL;
	newNode -> right = NULL;
		
	if(aux == NULL) {
		root = newNode;
	
	} else {
		
		while(aux -> right != NULL || aux -> left != NULL) {
			if(key > aux -> key) {
				if(aux -> right != NULL) {
					aux = aux -> right;
				} else {
					aux -> right = newNode;
				}
			}
			
			if(key < aux -> key) {
				if(aux -> left != NULL) {
					aux = aux -> left;
				} else {
					aux -> left = newNode; 
				}
			}	
		}
		
		if(key > aux -> key) {
			aux -> right = newNode;
		}
		
		if(key < aux -> key) {
			aux -> left = newNode;
		}
	}
	
	return root;
}

int main() {
	NodeBst *root = NULL;
	
	insert(root, 1, 10);
	insert(root, 2, 7);
	insert(root, 3, 5);
	insert(root, 4, 6);
	insert(root, 5, 9);
	insert(root, 6, 2);
	insert(root, 7, 16);
	insert(root, 8, 11);
	insert(root, 9, 15);
	insert(root, 10, 12);
	
	inOrder(root);
	
	return 0;
}
