#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * @depth: Current depth of the tree
 * @level: Level to check for perfection
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect(tree->left, depth, level + 1) &&
			binary_tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
	*root = new_node;
	return (new_node);
	}

	parent = binary_tree_get_insertion_node(*root);

	if (parent->left == NULL)
	parent->left = new_node;
	else
	parent->right = new_node;

	new_node->parent = parent;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
	swap_values(&new_node->n, &new_node->parent->n);
	new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_get_insertion_node - Gets the node where a value should be inserted
 * in a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node where the value should be inserted
 */
heap_t *binary_tree_get_insertion_node(heap_t *root)
{
	heap_t *insertion_node = NULL;
	size_t depth = 0;

	while (root != NULL)
	{
	if (binary_tree_is_perfect(root, depth, 0))
		insertion_node = root;

	depth++;
	if (root->left != NULL)
		root = root->left;
	else
	root = root->right;
	}

	return (insertion_node);
}

/**
 * swap_values - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
