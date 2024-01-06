#include "binary_trees.h"

/**
 * binary_tree_traverse - Traverse the binary tree at a specific level
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 * @level: Level to traverse in the tree
 */
void binary_tree_traverse(const binary_tree_t *tree, void (*func)(int), size_t level);

/**
 * binary_tree_levelorder - Perform a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	for (level = 1; level <= height; level++)
	binary_tree_traverse(tree, func, level);
}

/**
 * binary_tree_traverse - Traverse the binary tree at a specific level
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 * @level: Level to traverse in the tree
 */
void binary_tree_traverse(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
	func(tree->n);
	else if (level > 1)
	{
	binary_tree_traverse(tree->left, func, level - 1);
	binary_tree_traverse(tree->right, func, level - 1);
	}
}
