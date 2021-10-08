/**
 * Find out Maximum depth of a binary tree.
 */
#include <stdio.h>

#include "binary_tree.h"

int main(int argc, char *argv[])
{
    struct bt_node *root = NULL;

    bt_new_node(&root, 500);

    bst_insert(&root, 400);
    bst_insert(&root, 300);
    bst_insert(&root, 1000);
    bst_insert(&root, 50);
    bst_insert(&root, 10);
    
    printf("Expected Maxdepth: %d\n", 5);
    printf("Maxdepth: %d\n", bt_max_depth(root));
    print_all_nodes(root);
    return 0;
}
