#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size == 0)
	return NULL;

	/* Insert the first element to initialize the tree */
	root = avl_insert(&root, array[0]);

	/* Insert the remaining elements into the AVL tree */
	for (size_t i = 1; i < size; i++)
	{
	if (avl_insert(&root, array[i]) == NULL)
	{
	/* If insertion fails, free the tree and return NULL */
	binary_tree_delete(root);
	return NULL;
	}
	}

	return root;
}
