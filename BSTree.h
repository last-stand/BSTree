typedef struct tree BST;
typedef BST* BST_ptr;
struct tree{
	void* data;
	BST_ptr left;
	BST_ptr right;
};