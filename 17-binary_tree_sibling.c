#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a node in a binary tree
 * @node: Pointer to the node for which the sibling is to be found
 *
 * Return:
 * - Pointer to the sibling node.
 * - NULL if the node is NULL, has no parent, or the parent has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
