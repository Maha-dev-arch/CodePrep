#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node_t;

Node_t* createNode(int data) {
	Node_t* newNode = malloc(sizeof(Node_t));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node_t* insertNode(Node_t* root, int data) {
	if (root == NULL)
		return createNode(data);

	if (data < root->data)
		root->left = insertNode(root->left, data);
	else
		root->right = insertNode(root->right, data);

	return root;
}

void inOrderTraversal(Node_t* root) {
	if (root == NULL)
		return;

	inOrderTraversal(root->left);
	printf("%d->", root->data);
	inOrderTraversal(root->right);
}

//int main()
//{
//	Node_t* root = NULL;
//	root = insertNode(root, 20);
//	insertNode(root, 30);
//	insertNode(root, 10);
//	insertNode(root, 50);
//	insertNode(root, 40);
//	inOrderTraversal(root);
//	return 0;
//}