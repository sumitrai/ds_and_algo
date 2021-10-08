#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

// binary tree node: contains a key and (optional) value
struct bt_node {
    int data;
    struct bt_node *left;
    struct bt_node *right;
};

int bt_new_node(struct bt_node **node, int val);
int bt_max_depth(struct bt_node *root);
int bst_insert(struct bt_node **node, int val);
int bst_min_value(struct bt_node *node);
struct bt_node *bst_lookup(struct bt_node *root, int val);
int bt_size(struct bt_node *root);
int print_leaf_nodes(struct bt_node *node);
int print_all_nodes(struct bt_node *root);
int print_node(struct bt_node *node);
#endif
