#include "binary_trees.h"
#include "limits.h"

/**
 * height - Calculate the height of a Binary Tree
 * @tree: Pointer to the root node of the Binary Tree
 *
 * Return:
 * - The height of the Binary Tree.
 * - 0 if the tree is NULL.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Check if a Binary Tree is an AVL tree recursively
 * @tree: Pointer to the root node of the Binary Tree
 * @lo: The lower bound for node values in the subtree
 * @hi: The upper bound for node values in the subtree
 *
 * Return:
 * - 1 if the Binary Tree is an AVL tree.
 * - 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Check if a Binary Tree is an AVL tree
 * @tree: Pointer to the root node of the Binary Tree
 *
 * Return:
 * - 1 if the Binary Tree is an AVL tree.
 * - 0 otherwise or if the input tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
