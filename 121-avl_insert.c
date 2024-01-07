#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	/* Step 1: Perform standard BST insert */
	if (*tree == NULL)
	{
	/* Create a new node */
	*tree = binary_tree_node(NULL, value);
	if (*tree == NULL)
		return (NULL);
	return (*tree);
	}

	if (value < (*tree)->n)
	{
	(*tree)->left = avl_insert(&(*tree)->left, value);
	if ((*tree)->left == NULL)
		return (NULL);
	}
	else if (value > (*tree)->n)
	{
	(*tree)->right = avl_insert(&(*tree)->right, value);
	if ((*tree)->right == NULL)
		return (NULL);
	}
	else
	{
	/* Duplicate values are not allowed */
	return (NULL);
	}

	/* Step 2: Update height of the current node */
	/* Your code to update the height goes here */

	/* Step 3: Get the balance factor of this ancestor */
	/* Your code to get the balance factor goes here */

	/* Step 4: Perform rotations if needed */
	/* Your code to perform rotations goes here */

	/* Step 5: Return the updated root of the subtree */
	return (*tree);
}
