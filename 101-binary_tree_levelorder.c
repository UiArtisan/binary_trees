#include "binary_trees.h"

/**
 * binary_tree_height_add - Measure the height of a binary tree using addition
 * @tree: Pointer to the root node of the binary tree to be measured
 *
 * Return:
 * - The height of the tree as a size_t.
 * - 0 if the tree is NULL.
 */
size_t binary_tree_height_add(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = 1 + binary_tree_height_add(tree->left);

	height_r = 1 + binary_tree_height_add(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);

}

/**
 * printLevel - Print nodes at a specific level of a binary tree
 * @tree: Pointer to the root node of the binary tree
 * @level: The level of the nodes to be printed
 * @func: Pointer to the function to print the node values
 */
void printLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printLevel(tree->left, level - 1, func);
		printLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverse a binary tree in level order
 * @tree: Pointer to the root node of the binary tree
 * @func: Pointer to the function to perform on each node value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int i = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_add(tree) + 1;

	while (i <= height)
	{
		printLevel(tree, i, func);
		i++;
	}
}
