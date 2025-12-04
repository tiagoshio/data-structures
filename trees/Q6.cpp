#include <iostream>

using namespace std;

struct NodeTree {
	int data;
	NodeTree *left;
	NodeTree *right;
};

struct NodeStack {
	NodeTree *data;
	NodeStack *next;
};

void push(NodeStack *&top, NodeTree *value) {
	NodeStack *newTop = new NodeStack;
	newTop -> data = value;
	newTop -> next = top;
	
	top = newTop;	
}

NodeTree* pop(NodeStack *&top) {
	NodeStack *toDelete = top;
	
	NodeTree *data = toDelete -> data;
	
	top = top -> next;
	
	delete toDelete;
	
	return data;
}

void preOrder(NodeTree *root, NodeStack *&top) {
	NodeTree *aux = root;
	
	while(aux != NULL) {
		while(aux != NULL) {
			cout << aux -> data << endl;
			
			if(aux -> right != NULL) {
				push(top, aux);
			}
			
			aux = aux -> left;
		}
		
		if(top != NULL) {
			aux = pop(top);
			aux = aux -> right;
		}
	}
}

int main() {
	/*
	NodeTree *root = new NodeTree;
	root -> data = 2;
	root -> left = NULL;
	root -> right = NULL;
	
	NodeTree *nodeL = new NodeTree;
	nodeL -> data = 7;
	nodeL -> left = NULL;
	nodeL -> right = NULL;
	
	NodeTree *nodeR = new NodeTree;
	nodeR -> data = 5;
	nodeR -> left = NULL;
	nodeR -> right = NULL;
	
	root -> left = nodeL;
	root -> right = nodeR;
	
	NodeTree *nodeLL = new NodeTree;
	nodeLL -> data = 2;
	nodeLL -> left = NULL;
	nodeLL -> right = NULL;
	
	NodeTree *nodeLR = new NodeTree;
	nodeLR -> data = 6;
	nodeLR -> left = NULL;
	nodeLR -> right = NULL;
	
	nodeL -> left = nodeLL;
	nodeL -> right = nodeLR;
	
	NodeTree *nodeLRL = new NodeTree;
	nodeLRL -> data = 5;
	nodeLRL -> left = NULL;
	nodeLRL -> right = NULL;
	
	NodeTree *nodeLRR = new NodeTree;
	nodeLRR -> data = 11;
	nodeLRR -> left = NULL;
	nodeLRR -> right = NULL;
	
	nodeLR -> left = nodeLRL;
	nodeLR -> right = nodeLRR;
	
	NodeTree *nodeRR = new NodeTree;
	nodeRR -> data = 9;
	nodeRR -> left = NULL;
	nodeRR -> right = NULL;
	
	nodeR -> right = nodeRR;
	
	NodeTree *nodeRRL = new NodeTree;
	nodeRRL -> data = 4;
	nodeRRL -> left = NULL;
	nodeRRL -> right = NULL;
	
	nodeRR -> left = nodeRRL;
	*/
	
	NodeTree *root = new NodeTree;
	root -> data = 10;
	root -> left = NULL;
	root -> right = NULL;

	NodeTree *nodeL = new NodeTree;   // 5
	nodeL -> data = 5;
	nodeL -> left = NULL;
	nodeL -> right = NULL;
	
	NodeTree *nodeR = new NodeTree;   // 15
	nodeR -> data = 15;
	nodeR -> left = NULL;
	nodeR -> right = NULL;
	
	root -> left = nodeL;
	root -> right = nodeR;
	
	NodeTree *nodeLL = new NodeTree;  // 3
	nodeLL -> data = 3;
	nodeLL -> left = NULL;
	nodeLL -> right = NULL;
	
	NodeTree *nodeLR = new NodeTree;  // 7
	nodeLR -> data = 7;
	nodeLR -> left = NULL;
	nodeLR -> right = NULL;
	
	NodeTree *nodeRL = new NodeTree;  // 12
	nodeRL -> data = 12;
	nodeRL -> left = NULL;
	nodeRL -> right = NULL;
	
	NodeTree *nodeRR = new NodeTree;  // 18
	nodeRR -> data = 18;
	nodeRR -> left = NULL;
	nodeRR -> right = NULL;
	
	nodeL -> left = nodeLL;
	nodeL -> right = nodeLR;
	
	nodeR -> left = nodeRL;
	nodeR -> right = nodeRR;
	
	NodeTree *nodeLLR = new NodeTree; // 4 (Filho direito de 3)
	nodeLLR -> data = 4;
	nodeLLR -> left = NULL;
	nodeLLR -> right = NULL;
	
	NodeTree *nodeLRL = new NodeTree; // 6 (Filho esquerdo de 7)
	nodeLRL -> data = 6;
	nodeLRL -> left = NULL;
	nodeLRL -> right = NULL;
	
	nodeLL -> right = nodeLLR;
	
	nodeLR -> left = nodeLRL;
	
	//-----Pilha-----//
	
	NodeStack *top = NULL;
	
	preOrder(root, top);
	
	return 0;
}
