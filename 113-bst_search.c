#include "binary_trees.h"

/**
 * bst_search - Search for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: The value to search for in the BST
 *
 * Return:
 * - A pointer to the node containing the searched value.
 * - NULL if the value is not found or the tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
