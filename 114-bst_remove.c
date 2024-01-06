#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
        if (root == NULL)
                return NULL;

        if (value < root->n)
        root->left = bst_remove(root->left, value);
        else if (value > root->n)
        root->right = bst_remove(root->right, value);
        else 
        {
        if (root->left == NULL) {
        bst_t *temp = root->right;
        free(root);
        return temp;
        }
        else if (root->right == NULL) {
        bst_t *temp = root->left;
        free(root);
        return temp;
        }

        bst_t *successor = root->right;
        while (successor->left != NULL)
        successor = successor->left;

        root->n = successor->n;
        root->right = bst_remove(root->right, successor->n);
        }

        return root;
}
