/**
 * print binary search tree in increasing order.
 */
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

/*
 * Sample Tree:
 *     10
 *    /  \
 *   7    12
 *  / \    \
 * 3   8   15
 *
 */
enum bt_print_flags {
    BT_PRINT_IN_ORDER,  // print 3, 7, 8, 10, 12, 15
};

int is_leaf_node(struct bt_node *node)
{
    if ((node->left == NULL) && (node->right == NULL))
        return 1;
    else
        return 0;
}

void print_bst(struct bt_node *root, int flags)
{
    if (root == NULL) return;
    
    switch (flags) {
    case BT_PRINT_IN_ORDER:
      print_bst(root->left, flags);
      printf("%d ", root->data);
      print_bst(root->right, flags);
      break;
    default:
      print_all_nodes(root);
    }
}

/*
 * Sample Tree:
 *     10
 *    /  \
 *   7    12
 *  / \    \
 * 3   8   15
 *
 */
int main(int argc, char *argv[], char *envp[])
{
    struct bt_node *root = NULL;

    bt_new_node(&root, 10);
    bst_insert(&root, 7);
    bst_insert(&root, 3);
    bst_insert(&root, 8);
    bst_insert(&root, 12);
    bst_insert(&root, 15);

    print_bst(root, BT_PRINT_IN_ORDER);
    printf("\n");
    return 0;
}
