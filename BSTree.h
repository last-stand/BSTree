typedef struct node Node;
typedef struct node* Node_ptr;
struct node{
	int data;
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
Node_ptr createTreeNode(int data);

Node_ptr insertNewNode(Node_ptr walker, int data);
int insert(BSTree *, int);
Node * find(BSTree, int);