#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_complete(tree, binary_tree_size(tree), 0))
		return (0);

	return (is_max_heap(tree));
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree
 * @size: The size of the tree
 * @index: The current index
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t size, size_t index)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete(tree->left, size, 2 * index + 1) &&
			binary_tree_is_complete(tree->right, size, 2 * index + 2));
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
