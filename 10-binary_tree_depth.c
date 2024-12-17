#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree
 * @tree: Pointer to the node for which depth is to be measured
 *
 * Return:
 * - The depth of the node as a size_t.
 * - 0 if the node is NULL or has no parent.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
