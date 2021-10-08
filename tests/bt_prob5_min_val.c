/**
 * Find out Minimum value in a binary search tree.
 */
#include <stdio.h>

#include "binary_tree.h"

int main(int argc, char *argv[])
{
    struct bt_node *root = NULL;

    bst_insert(&root, 400);
    bst_insert(&root, 300);
    bst_insert(&root, 1);
    bst_insert(&root, 250);
    bst_insert(&root, 1000);
    bst_insert(&root, 2);

    printf("Expected Min Value: 1\n");
    printf("Min Value: %d\n", bst_min_value(root));
    return 0;
}
