#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree
 * @node: Pointer to the node to be checked
 *
 * Return:
 * - 1 if the node is a leaf.
 * - 0 if the node is NULL or has at least one child.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
