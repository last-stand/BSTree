#include <stdio.h>
#include "BSTree.h"
#include "expr_assert.h"

void test_createBSTree_should_create_an_empty_tree(){
	BSTree BST = createBSTree();
	assert(BST.root == NULL);
}