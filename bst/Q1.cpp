#include <iostream>

using namespace std;

struct Student {
	string name;
	int age;
	string registration;
};

struct NodeBst {
	Student data;
	int key;
	NodeBst *left;
	NodeBst *right;
};

NodeBst* insert(NodeBst *&root, Student student, int key) {
	if(root == NULL) {
		NodeBst *newNode = new NodeBst;
		newNode -> data = student;
		newNode -> key = key;
		newNode -> left = NULL;
		newNode -> right = NULL;
		
		root = newNode;
		
		return root;
		
	} else if(key > root -> key) {
		root -> right = insert(root -> right, student, key);
		
	} else if(key < root -> key) {
		root -> left = insert(root -> left, student, key);
		
	} else {
		cout << "Nao eh possivel adicionar, chave ja existe!";
	}
	
	return root;
}

string search(NodeBst *root, int key) {
	if(root != NULL) {
		if(key > root -> key) {
			return search(root -> right, key);
		}
		
		if(key < root -> key) {
			return search(root -> left, key);
		}
		
		return root -> data.name;
	}
	
	return "nada foi encontrado";
}

NodeBst* remove(NodeBst *&root, int key) {
	if(root == NULL) {
		return root;
		
	} else if(key > root -> key) {
		root -> right = remove(root -> right, key);
		
	} else if(key < root -> key) {
		root -> left = remove(root -> left, key);
		
	} else {
		if(root -> left == NULL && root -> right == NULL) {
			delete root;
			
			root = NULL;
			
			return root;
			
		} else if(root -> right == NULL) {
			NodeBst *aux = root;
			
			root = root -> left;
			
			delete aux;
			return root;
			
		} else if(root -> left == NULL) {
			NodeBst *aux = root;
			
			root = root -> right;
			
			delete aux;
			return root;
			
		} else {
			NodeBst *aux = root -> left;
			
			while(aux -> right != NULL) {
				aux = aux -> right;
			}
			
			root -> data = aux -> data;
			root -> key = aux -> key;
			root -> left = remove(root -> left, root -> key);
			
		}
	}
	
	return root;
}

void inOrder(NodeBst *root) {
	if(root != NULL) {
		inOrder(root -> left);
		cout << root -> data.name << "(" << root -> key << ")" << endl;
		inOrder(root -> right);
	}
}

int main() {
	
	Student me;
	me.name = "Tiago";
	me.age = 20;
	me.registration = "2024.2-001";
	
	Student dalina;
	dalina.name = "Dalina";
	dalina.age = 21;
	dalina.registration = "2024.2-002";
	
	Student matheus;
	matheus.name = "Matheus";
	matheus.age = 22;
	matheus.registration = "2024.2-003";
	
	Student rian;
	rian.name = "Rian";
	rian.age = 24;
	rian.registration = "2024.2-004";
	
	Student laires;
	laires.name = "Laires";
	laires.age = 27;
	laires.registration = "2024.2-005";
	
	Student felipe;
	felipe.name = "Felipe";
	felipe.age = 31;
	felipe.registration = "2024.2-006";
	
	Student cristopher;
	cristopher.name = "Cristopher";
	cristopher.age = 35;
	cristopher.registration = "2024.2-007";
	
	Student winicius;
	winicius.name = "Winicius";
	winicius.age = 24;
	winicius.registration = "2024.2-008";
	
	Student lucas;
	lucas.name = "Lucas";
	lucas.age = 23;
	lucas.registration = "2024.2-009";
	
	Student giovanni;
	giovanni.name = "Giovanni";
	giovanni.age = 22;
	giovanni.registration = "2024.2-010";
	
	Student roselanio;
	roselanio.name = "Roselanio";
	roselanio.age = 25;
	roselanio.registration = "2024.2-011";
	
	NodeBst *root = NULL;
	
	insert(root, me, 10);
	insert(root, dalina, 7);
	insert(root, matheus, 5);
	insert(root, rian, 6);
	insert(root, laires, 9);
	insert(root, felipe, 2);
	insert(root, cristopher, 16);
	insert(root, winicius, 11);
	insert(root, lucas, 15);
	insert(root, giovanni, 12);
	
	//inOrder(root);
	
	remove(root, 17);
	
	//cout << search(root, 14) << endl;
	
	return 0;	
}
