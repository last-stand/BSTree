typedef struct node Node;
typedef Node* Node_ptr;
struct node{
	void* data;
	Node_ptr left;
	Node_ptr right;
};

typedef struct tree BSTree;
typedef BSTree* BSTree_ptr;
struct tree
{
	Node_ptr root;
};
BSTree createBSTree(void);
int insert(BSTree *, int);
Node * find(BSTree, int);