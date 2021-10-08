/**
 * Count the number of nodes in a given tree.
 */
#include <stdio.h>

#include "utils.h"
#include "binary_tree.h"

int main(int argc, char *argv[], char *envp[])
{
    struct bt_node *root = NULL;
    bst_insert(&root, 10);
    bst_insert(&root, 5);
    bst_insert(&root, 6);
    bst_insert(&root, 20);
    bst_insert(&root, 30);
    printf("Size: %d\n", bt_size(root));
    return 0;
}
