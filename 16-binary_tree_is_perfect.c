#include "binary_trees.h"

/**
 * is_leaf - Check if a node is a leaf in a binary tree
 * @node: Pointer to the node to be checked
 *
 * Return:
 * - 1 if the node is a leaf.
 * - 0 if the node has at least one child or is NULL.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Calculate the depth of a node in a binary tree
 * @tree: Pointer to the node for which depth is to be calculated
 *
 * Return:
 * - The depth of the node as a size_t.
 * - 0 if the node is NULL or has no parent.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Find a leaf node in a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - Pointer to a leaf node in the binary tree.
 * - NULL if the tree is NULL or does not have any leaves.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Check if a binary tree is perfect recursively
 * @tree: Pointer to the root node of the binary tree to be checked
 * @leaf_depth: Depth of the leaf nodes in the tree
 * @level: Current level in the tree
 *
 * Return:
 * - 1 if the tree is perfect.
 * - 0 if the tree is not perfect.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree to be checked
 *
 * Return:
 * - 1 if the tree is perfect.
 * - 0 if the tree is not perfect or is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
