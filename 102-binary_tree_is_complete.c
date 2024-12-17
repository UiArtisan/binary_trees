#include "binary_trees.h"

/**
 * create_node - Create a new node for level-order traversal queue
 * @node: Pointer to the binary tree node to be stored in the new node
 *
 * Return:
 * - Pointer to the newly created level-order queue node.
 * - NULL if memory allocation fails.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Free the memory allocated for a level-order traversal queue
 * @head: Pointer to the head of the level-order queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Add a node to the end of a level-order traversal queue
 * @node: Pointer to the binary tree node to be added
 * @head: Pointer to the head of the level-order queue
 * @tail: Pointer to the tail of the level-order queue
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Remove the front node from a level-order traversal queue
 * @head: Pointer to the head of the level-order queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the binary tree to be checked
 *
 * Return:
 * - 1 if the tree is complete.
 * - 0 if the tree is not complete or is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
