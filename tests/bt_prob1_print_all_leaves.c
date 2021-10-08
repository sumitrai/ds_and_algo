#include <stdio.h>

#include "binary_tree.h"

int main(int argc, char *argv[], char *envp[])
{
    struct bt_node *root = NULL;

    bt_new_node(&root, 100);
    bst_insert(&root, 200);
    bst_insert(&root, 20);
    bst_insert(&root, 60);
    bst_insert(&root, 150);
    
    printf("##################################################\n");
    printf("Purpose: print all leaf nodes of binary tree\n");
    printf("Expected Final List: 60, 150\n");

    return print_leaf_nodes(root);
}
