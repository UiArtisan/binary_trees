#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Check if a binary tree is a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the binary tree
 * @lo: The lower bound for the current subtree
 * @hi: The upper bound for the current subtree
 *
 * Return:
 * - 1 if the subtree is a valid BST.
 * - 0 if the subtree is not a valid BST.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Check if a binary tree
 *          is a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - 1 if the tree is a valid BST.
 * - 0 if the tree is not a valid BST or is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
