#ifndef TREE_H_
#define TREE_H_

typedef struct TreeNode
{
	void* data;
	struct TreeNode* parent;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


typedef struct Tree
{
	TreeNode* root;
	int count;

	/* this function to compare nodes
	 * returns 0 if both are equal
	 * returns -1 if paramer1 < parameter2
	 * returns 1 if parameter1 > parameter	*/
	int (*node_compare)(void*, void*);

	/* Function pointer for printing tree elements */
	void (*print_item)(void*);
}Tree;


Tree* initialize_Tree();

int tree_size(Tree* tree);

_Bool is_tree_empty(Tree* tree);

int depth_of_TreeNode(TreeNode* TreeNode);

int height_of_TreeNode(Tree* tree, TreeNode* TreeNode);

void* get_tree_elements(Tree* tree);

void insert_into_tree(Tree* tree, void* element);

void print_tree(Tree* tree);



#endif
