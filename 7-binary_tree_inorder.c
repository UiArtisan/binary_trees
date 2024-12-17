#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree using in-order traversal
 * @tree: Pointer to the root node of the binary tree to be traversed
 * @func: Pointer to the function to be called on each node's value
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
