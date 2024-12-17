#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of a node in a binary tree
 * @node: Pointer to the node for which the uncle is to be found
 *
 * Return:
 * - Pointer to the uncle node.
 * - NULL if the node is NULL, has no parent, the parent has no sibling,
 * or the parent has no parent.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
