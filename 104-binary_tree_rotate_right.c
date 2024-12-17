#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Perform a right-rotation on a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - Pointer to the new root of the rotated binary tree.
 * - NULL if the tree is NULL or has no left child.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tmp = pivot->right;
	pivot->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
