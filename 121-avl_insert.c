#include "binary_trees.h"


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
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Calculate the balance factor of a Binary Tree node
 * @tree: Pointer to the node of the Binary Tree
 *
 * Return:
 * - The balance factor of the Binary Tree node.
 * - 0 if the tree is NULL.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Insert a value into an AVL tree recursively
 * @tree: Pointer to the root node of the AVL tree
 * @parent: Pointer to the parent node of the current node
 * @new: Pointer to store the newly inserted node
 * @value: The value to be inserted into the AVL tree
 *
 * Return:
 * - A pointer to the root of the AVL tree after insertion.
 * - NULL if memory allocation fails.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Insert a value into an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 * @value: The value to be inserted into the AVL tree
 *
 * Return:
 * - A pointer to the newly inserted node.
 * - NULL if memory allocation fails
 *      or if the input tree pointer is NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
