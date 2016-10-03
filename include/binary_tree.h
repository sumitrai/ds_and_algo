#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

// binary tree node: contains a key and (optional) value
struct bt_node {
    int data;
    struct bt_node *left;
    struct bt_node *right;
};

int bt_new_node(struct bt_node **node, int val);
int bst_insert(struct bt_node **node, int val);
struct bt_node *bst_lookup(struct bt_node *root, int val);
int print_leaf_nodes(struct bt_node *node);
#endif
