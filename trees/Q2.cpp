#include <iostream>

using namespace std;

struct NodeTree {
	int data;
	NodeTree *left;
	NodeTree *right;
};

void posOrderPair(NodeTree *root) {
	if(root != NULL) {
		posOrderPair(root -> left);
		posOrderPair(root -> right);
		
		if(((root -> data) % 2) == 0) {
			cout << root -> data << endl;
		}
	}
}

void posOrderOdd(NodeTree *root) {
	if(root != NULL) {
		posOrderOdd(root -> left);
		posOrderOdd(root -> right);
		
		if(((root -> data) % 2) == 1) {
			cout << root -> data << endl;
		}
	}
}

int main() {
	
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
	
	posOrderOdd(root);
	
	return 0;
}
