#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

// binary tree node: contains a key and (optional) value
struct bt_node {
    int data;
    struct bt_node *left;
    struct bt_node *right;
};

struct bt_node *bt_new_node(int val);
void bt_insert(struct bt_node **node, int val);
struct bt_node *bt_lookup(struct bt_node *root, int val);
#endif
