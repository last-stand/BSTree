#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

BSTree createBSTree(void){
	BSTree bst;
	bst.root = NULL;
	return bst;
};

Node_ptr createTreeNode(int data){
	Node_ptr node = calloc(1,sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node_ptr insertNewNode(Node_ptr walker, int data){
	if(walker == NULL)
		return createTreeNode(data);
	if(data >= walker->data)
		walker->right = insertNewNode(walker->right, data);		
	else
		walker->left = insertNewNode(walker->left, data);	
	return walker;
}

int insert(BSTree * tree, int data){
	if(tree->root == NULL){
		tree->root = createTreeNode(data);
		return 1;
	}
	insertNewNode(tree->root, data);
	return 1;
};

Node_ptr search(Node_ptr root,int data){
	if(root == NULL || root->data == data)
		return root;
	if(data > root->data)
		return search(root->right, data);
	return search(root->left,data);
}

Node * find(BSTree tree, int data){
	return search(tree.root, data);
};