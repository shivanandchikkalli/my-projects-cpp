#include <stdlib.h>
#include <stdio.h>

#include "tree.h"
#include "dll.h"


Tree* initialize_Tree()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	if(!tree)
	{
		printf("Memory allocation failed...");
		return NULL;
	}
	tree->count = 0;
	tree->root = NULL;

	return tree;
}

int tree_size(Tree* tree)
{
	return tree->count;
}

_Bool is_tree_empty(Tree* tree)
{
	return tree->count == 0;
}

int depth_of_TreeNode(TreeNode* node)
{
	if(node != NULL)
	{
		if(node->parent == NULL)
			return 0;
		else
			return 1 + depth_of_TreeNode(node->parent);
	}
	return 0;
}

void preorder_traversal_of_node(TreeNode* node, List* list)
{
	if(node != NULL)
	{
		addFront(list, node);
		preorder_traversal_of_node(node->left, list);
		preorder_traversal_of_node(node->right, list);
	}
}

void postorder_traversal_of_node(TreeNode* node, List* list)
{
	if(node != NULL)
	{
		postorder_traversal_of_node(node->left, list);
		postorder_traversal_of_node(node->right, list);
		addFront(list, node);
	}
}

void inorder_traversal_of_node(TreeNode* node, List* list)
{
	if(node != NULL)
	{
		inorder_traversal_of_node(node->left, list);
		addFront(list, node);
		inorder_traversal_of_node(node->right, list);
	}
}

void* get_tree_elements(Tree* tree)
{
	if(tree != NULL)
	{
		List* treeElements = createList();
		//preorder_traversal_of_node(tree->root, treeElements);
		//postorder_traversal_of_node(tree->root, treeElements);
		inorder_traversal_of_node(tree->root, treeElements);
		return treeElements;
	}
	return NULL;
}

int height_of_TreeNode(Tree* tree, TreeNode* node)
{
	if(tree != NULL && node != NULL)
	{
		if(node->left == NULL && node->right ==NULL)
		{
				return 0;
		}
		else
		{
			int x = height_of_TreeNode(tree, node->left);
			int y = height_of_TreeNode(tree, node->right);
			if(x > y)
				return x+1;
			else
				return y+1;
		}
	}
	return 0;
}

TreeNode* get_tree_node(void* data)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void add_node(Tree* tree, TreeNode* node, void* data)
{
	if(tree->node_compare(node->data, data) == 1)
	{
		if(node->left == NULL)
		{
			TreeNode* newNode = get_tree_node(data);
			newNode->parent = node;
			node->left = newNode;
		}
		else
			add_node(tree, node->left, data);
	}
	else if(tree->node_compare(node->data, data) == -1)
	{
		if(node->right == NULL)
		{
			TreeNode* newNode = get_tree_node(data);
			newNode->parent = node;
			node->right = newNode;
		}
		else
			add_node(tree, node->right, data);
	}
}

void insert_into_tree(Tree* tree, void* element)
{
	if(tree->count == 0)
	{
		tree->root = get_tree_node(element);
	}
	else
	{
		add_node(tree, tree->root, element);
	}
	tree->count++;
}

void print_tree(Tree* tree)
{
	List* treeElements = (List*)get_tree_elements(tree);
	int treeSize = tree_size(tree);
	for(int i = treeSize-1; i >= 0; i--)
	{
		TreeNode* node = (TreeNode*)(get_list_item_by_index(treeElements, i)->element);
		tree->print_item(node->data);
	}
}




