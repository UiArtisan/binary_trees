#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the number of nodes in a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - The number of nodes in the binary tree as a size_t.
 * - 0 if the tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
