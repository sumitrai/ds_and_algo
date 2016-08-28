#include <stdlib.h>

#include "binary_tree.h"

struct bt_node *bt_new_node(int val)
{
    struct bt_node *bt_node_ptr = malloc(sizeof(struct bt_node));
    if (bt_node_ptr) {
        bt_node_ptr->data = val;
        bt_node_ptr->left = bt_node_ptr->right = NULL;
    }
    return bt_node_ptr;
}

void bt_insert(struct bt_node **node, int val)
{
    assert(node != NULL);
    if (*node == NULL) {
        *node = bt_new_node(val);
        assert(*node != NULL);
    } else if (val <= (*node)->data)
        bt_insert(&(*node)->left, val);
    else
        bt_insert(&(*node)->right, val);
}

struct bt_node *bt_lookup(struct bt_node *root, int val)
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
                return bt_lookup(root->left, val);
            else
                return bt_lookup(root->right, val);
        }
    }
}
