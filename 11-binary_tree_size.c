#include "binary_trees.h"

/**
 * binary_tree_size - Calculate the size (number of nodes) of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - The size of the binary tree as a size_t.
 * - 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
