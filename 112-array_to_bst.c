#include "binary_trees.h"

/**
 * array_to_bst - Convert an array to a Binary Search Tree (BST)
 * @array: Pointer to the array containing unique integer values
 * @size: The number of elements in the array
 *
 * Return:
 * - A pointer to the root of the constructed BST.
 * - NULL if the array is NULL or memory allocation fails.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
