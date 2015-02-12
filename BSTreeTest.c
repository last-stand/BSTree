#include <stdio.h>
#include "BSTree.h"
#include "expr_assert.h"

BSTree bst;
BSTree_ptr bst_ptr;
int data, data2, result;

void test_createBSTree_should_create_an_empty_tree(){
	bst = createBSTree();
	assert(bst.root == NULL);
}

void test_createTreeNode_should_create_a_tree_node_with_given_data(){
	int num = 10;
	Node_ptr node = createTreeNode(num);
	assertEqual(node->data, 10);
}

void test_createTreeNode_should_create_a_tree_node_left_NULL(){
	int num = 10;
	Node_ptr node = createTreeNode(num);
	assert(node->left == NULL);
}

void test_createTreeNode_should_create_a_tree_node_right_NULL(){
	int num = 10;
	Node_ptr node = createTreeNode(num);
	assert(node->right == NULL);
}

void test_insert_should_enter_first_element_to_root_if_root_is_NULL(){
	data = 10;
	bst = createBSTree();
	bst_ptr = &bst;
	result = insert(bst_ptr, data);
	assertEqual(result, 1);
	assertEqual(bst.root->data, 10);
}

void test_insert_should_enter_next_element_to_the_right_of_root_if_number_is_bigger_than_root(){
	data = 10, data2 = 20;
	bst = createBSTree();
	bst_ptr = &bst;
	result = insert(bst_ptr, data);
	result = insert(bst_ptr, data2);
	assertEqual(bst.root->data, 10);
	assertEqual(bst.root->right->data, 20);
}

void test_insert_should_enter_next_element_to_the_left_of_root_if_number_is_smaller_than_root(){
	data = 10, data2 = 5;
	bst = createBSTree();
	bst_ptr = &bst;
	insert(bst_ptr, data);	insert(bst_ptr, data2);
	assertEqual(bst.root->data, 10);
	assertEqual(bst.root->left->data, 5);
}

void test_insert_should_enter_next_element_to_the_left_of_root_if_number_is_same_as_root(){
	data = 10, data2 = 10;
	bst = createBSTree();
	bst_ptr = &bst;
	result = insert(bst_ptr, data);
	result = insert(bst_ptr, data2);
	assertEqual(bst.root->data, 10);
	assertEqual(bst.root->right->data, 10);
}

void test_find_should_return_NULL_if_root_of_tree_is_NULL(){
	bst = createBSTree();
	assert(find(bst, 10) == NULL);
}

void test_find_should_return_root_if_given_data_is_in_root_of_tree(){
	data = 10;
	bst = createBSTree();
	bst_ptr = &bst;
	insert(bst_ptr, data);
	assert(find(bst, data)->data == 10);
}

void test_find_should_return_right_node_of_root_if_data_is_greater_than_root_data(){
	data = 10, data2 = 20;
	bst = createBSTree();
	bst_ptr = &bst;
	insert(bst_ptr, data);
	insert(bst_ptr, data2);
	assert(find(bst, data2)->data == 20);
}

void test_find_should_return_left_node_of_root_if_data_is_greater_than_root_data(){
	data = 50, data2 = 20;
	bst = createBSTree();
	bst_ptr = &bst;
	insert(bst_ptr, data);
	insert(bst_ptr, data2);
	assert(find(bst, data2)->data == 20);
}