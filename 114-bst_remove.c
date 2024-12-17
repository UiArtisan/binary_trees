#include "binary_trees.h"

/**
 * inorder_successor - Find the inorder successor in a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 *
 * Return:
 * - A pointer to the inorder successor node.
 * - NULL if the input node is NULL or the successor is not found.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Delete a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 * @node: Pointer to the node to be deleted from the BST
 *
 * Return:
 * - A pointer to the new root of the BST after deletion.
 * - NULL if memory allocation fails or the input node is NULL.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Remove a value from a Binary
 *          Search Tree (BST) recursively
 * @root: Pointer to the root node of the BST
 * @node: Pointer to the current node being checked
 * @value: The value to be removed from the BST
 *
 * Return:
 * - A pointer to the new root of the BST after removal.
 * - NULL if the value is not found, memory allocation fails,
 *      or the input node is NULL.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Remove a value from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 * @value: The value to be removed from the BST
 *
 * Return:
 * - A pointer to the new root of the BST after removal.
 * - NULL if the value is not found, memory allocation fails,
 *      or the input root is NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
