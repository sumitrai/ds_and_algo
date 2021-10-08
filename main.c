#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "binary_tree.h"

int main(int argc, char *argv[], char *envp[])
{
    // Note: Previous Linked-List feedback applied here - root is now on heap
    struct bt_node *root = NULL;
    
    if (bt_new_node(&root, 10)) {
        fprintf(stderr, "Failed to allocate memory for root node: %s\n",
                strerror(errno));
        return 1;
    }
    
    // Add some more element here
    if (bst_insert(&root, 5)) {
        fprintf(stderr, "failed to insert %d\n", 5);
    }
    if (bst_insert(&root, 6)) {
        fprintf(stderr, "failed to insert %d\n", 6);
    }

    if (bst_insert(&root, 4)) {
        fprintf(stderr, "failed to insert %d\n", 4);
    }

    // Verify that all elements are inserted
    printf("%d: %s\n", 10, bst_lookup(root, 10) == NULL ? "not found" : "found");
    printf("%d: %s\n", 5, bst_lookup(root, 5) == NULL ? "not found" : "found");
    printf("%d: %s\n", 6, bst_lookup(root, 6) == NULL ? "not found" : "found");
    printf("%d: %s\n", 4, bst_lookup(root, 4) == NULL ? "not found" : "found");
    printf("%d: %s\n", 9, bst_lookup(root, 9) == NULL ? "not found" : "found");

    return 0;
}
