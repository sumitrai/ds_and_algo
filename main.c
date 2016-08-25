#include <stdio.h>

#include "binary_tree.h"

int main(int argc, char *argv[], char *envp[])
{
    // Note: Previous Linked-List feedback applied here - root is now on heap
    struct bt_node *root = bt_new_node(10);

    // Add some more element here
    bt_insert(&root, 5);
    bt_insert(&root, 6);
    bt_insert(&root, 4);

    // Verify that all elements are inserted
    printf("%d: %s\n", 10, bt_lookup(root, 10) == NULL ? "not found" : "found");
    printf("%d: %s\n", 5, bt_lookup(root, 5) == NULL ? "not found" : "found");
    printf("%d: %s\n", 6, bt_lookup(root, 6) == NULL ? "not found" : "found");
    printf("%d: %s\n", 4, bt_lookup(root, 4) == NULL ? "not found" : "found");
    printf("%d: %s\n", 9, bt_lookup(root, 9) == NULL ? "not found" : "found");

    return 0;
}
