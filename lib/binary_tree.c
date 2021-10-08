#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

// create a new binary tree node: return 1 on failure, 0 on success
int bt_new_node(struct bt_node **bt_node, int val)
{
    if (bt_node == NULL) {
        fprintf(stderr, "%s: first argument is NULL\n", __func__);
        return 1;
    }
    *bt_node = malloc(sizeof(*bt_node));
    if (*bt_node == NULL) {
        fprintf(stderr, "%s: memory allocation failed: %s\n", __func__,
                strerror(errno));
        return 1;
    }
    (*bt_node)->data = val;
    (*bt_node)->left = (*bt_node)->right = NULL;
    return 0;
}

// inser a node into binary search tree: return 1 on failure, 0 on success
int bst_insert(struct bt_node **node, int val)
{
    assert(node != NULL);

    // empty node: insert val here
    if (*node == NULL) {
        if (bt_new_node(node, val)) return 1;
    } else {
	// non-empty node: insert left or right based upon val
	if (val <= (*node)->data) {
	    if (bst_insert(&(*node)->left, val)) return 1;
	} else {
	    if (bst_insert(&(*node)->right, val)) return 1;
	}
    }
    return 0;
}

struct bt_node *bst_lookup(struct bt_node *root, int val)
{
    // empty root: nothing to search into
    if (root == NULL)
        return NULL;
    else {
        // root not empty: check if root is a match
        if (val == root->data)
            return root;
        else {
            // root is not a match: check the left, right
            if (val < root->data)
                return bst_lookup(root->left, val);
            else
                return bst_lookup(root->right, val);
        }
    }
}

// returns size of binary tree
int bt_size(struct bt_node *root)
{
    if (root == NULL) {
	return 0;
    } else {
	return bt_size(root->left) + 1 + bt_size(root->right);
    }
}

// returns maximum depth of binary tree
int bt_max_depth(struct bt_node *node)
{
    if (node == NULL) {
	return 0;
    } else {
	// compute depth of each sub-tree
	int ldepth = bt_max_depth(node->left);
	int rdepth = bt_max_depth(node->right);

	// and return the larger one
	if (ldepth > rdepth) return ldepth + 1;
	else return rdepth + 1;
    }
}

// returns minimum value in binary search tree
int bst_min_value(struct bt_node *node)
{
    assert(node != NULL);  // make sure tree is non-empty

    for (; node->left != NULL; node = node->left) ;
    return node->data;
}

int print_leaf_nodes(struct bt_node *node)
{
    if (node == NULL) {
        fprintf(stdout, "%s: Warn: first argument 'node' is NULL\n", __func__);
        return 1;
    }
    // leaf node => left = right = NULL
    if ((node->left == NULL) && (node->right == NULL)) {
        printf("Leaf: %d\n", node->data);
    } else {
        // not a leaf node: traverse down left and right
        if (node->left)
            print_leaf_nodes(node->left);
        if (node->right)
            print_leaf_nodes(node->right);
    }
    return 0;
}

int print_all_nodes(struct bt_node *root)
{
    if (root == NULL) {
        fprintf(stderr, "%s: first argument 'root' is NULL\n", __func__);
        return 1;
    }
    print_node(root);
    if (root->left)
        print_all_nodes(root->left);
    if (root->right)
        print_all_nodes(root->right);
    return 0;
}

int print_node(struct bt_node *node)
{
    if (node == NULL) {
        fprintf(stderr, "%s: first argument 'node' is NULL\n", __func__);
        return 1;
    }
    printf("node: %d\n", node->data);
    if (node->left)
        printf("lchild: %d\n", node->left->data);
    if (node->right)
        printf("rchild: %d\n", node->right->data);
    return 0;
}
