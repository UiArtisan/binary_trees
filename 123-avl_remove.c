#include "binary_trees.h"

/**
 * bal - Balance an AVL tree recursively
 * @tree: Pointer to the root node of the AVL tree
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Find the successor of a node in a Binary Search Tree
 * @node: Pointer to the node for which the successor is to be found
 *
 * Return:
 * - The key of the successor node.
 * - 0 if the node is NULL or there is no successor.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 * remove_type - Remove a node from a Binary
 *      Search Tree (BST) based on its type
 * @root: Pointer to the root node of the BST
 *
 * Return:
 * - The key of the removed node.
 * - 0 if the node is not found or the tree is empty.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node with a specific value from
 *      a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST
 * @value: Value of the node to be removed
 *
 * Return:
 * - Pointer to the updated root of the BST.
 * - NULL if the specified value is not found or the tree is empty.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Remove a node with a specific value from an AVL Tree
 * @root: Pointer to the root node of the AVL Tree
 * @value: Value of the node to be removed
 *
 * Return:
 * - Pointer to the updated root of the AVL Tree.
 * - NULL if the specified value is not found or the tree is empty.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
