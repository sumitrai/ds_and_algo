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
    *bt_node = malloc(sizeof(struct bt_node));
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
    if (*node == NULL) {
        if (bt_new_node(node, val)) return 1;
    } else if (val <= (*node)->data) {
        if (bst_insert(&(*node)->left, val)) return 1;
    } else {
        if (bst_insert(&(*node)->right, val)) return 1;
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
