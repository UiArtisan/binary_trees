#include "binary_trees.h"

/**
 * aux_sort - Build an AVL Tree from a sorted array
 * @parent: Parent node in the AVL Tree (used for casting)
 * @array: Sorted array of integers
 * @begin: Starting index of the subarray
 * @last: Ending index of the subarray
 *
 * Return:
 * - Pointer to the root of the constructed AVL Tree.
 * - NULL if the subarray is empty or invalid.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Convert a sorted array to an AVL Tree
 * @array: Sorted array of integers
 * @size: Number of elements in the array
 *
 * Return:
 * - Pointer to the root of the constructed AVL Tree.
 * - NULL if the array is empty or NULL.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
