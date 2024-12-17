#include "binary_trees.h"


/**
 * b_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - Height of the binary tree.
 * - 0 if the tree is empty.
 */
int b_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + b_height(tree->left)
		+ b_height(tree->right));
}


/**
 * is_complete - Check if a binary tree is complete
 * @root: Pointer to the root node of the binary tree
 * @index: Current index of the node in the binary tree
 * @n_nodes: Total number of nodes in the binary tree
 *
 * Return:
 * - 1 if the binary tree is complete.
 * - 0 if the binary tree is not complete or if it is empty.
 */
int is_complete(const binary_tree_t *root, int index, int n_nodes)
{
	if (root == NULL)
		return (1);
	if (index >= n_nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, n_nodes) &&
		is_complete(root->right, 2 * index + 2, n_nodes));
}

/**
 * is_heap - Check if a binary tree is a max heap
 * @node: Pointer to the root node of the binary tree
 *
 * Return:
 * - 1 if the binary tree is a max heap.
 * - 0 if the binary tree is not a max heap or if it is empty.
 */
int is_heap(const binary_tree_t *node)
{
	if (!node->left && !node->right)
		return (1);
	if (!node->right)
		return (node->n >= node->left->n);
	if (node->n >= node->left->n
	    && node->n >= node->right->n)
		return ((is_heap(node->left))
			&& (is_heap(node->right)));
	else
		return (0);
}

/**
 * binary_tree_is_heap - Check if a binary tree is a max heap
 * @tree: Pointer to the root node of the binary tree
 *
 * Return:
 * - 1 if the binary tree is a max heap.
 * - 0 if the binary tree is not a max heap or if it is empty.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int height = b_height(tree);
	int index = 0;

	if (!tree)
		return (0);

	if (is_complete(tree, index, height) && is_heap(tree))
		return (1);
	return (0);
}
