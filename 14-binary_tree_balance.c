#include "binary_trees.h"

/**
 * binary_tree_balance - Measure the balance factor of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - The balance factor of the binary tree as an integer.
 * - 0 if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the binary tree to be measured
 *
 * Return:
 * - The height of the tree as a size_t.
 * - 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
