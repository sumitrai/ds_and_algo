/**
 * Build Binary tree:
 *          2
 *        /  \
 *       1   3
 * three different ways:
 * a: use 3 pointer variables and call new node three times.
 * b: use 1 pointer variable and call new node three times.
 * c: call insert 3 times and pass it root pointer.
 */
#include <stdio.h>

#include "utils.h"
#include "binary_tree.h"

int build123a()
{
    struct bt_node *root, *lchild, *rchild;
    LOG_ENTRY;
    root = lchild = rchild = NULL;
    bt_new_node(&root, 2);
    bt_new_node(&lchild, 1);
    bt_new_node(&rchild, 3);
    root->left = lchild;
    root->right = rchild;
    print_all_nodes(root);
    LOG_EXIT;
    return 0;
}

int build123b()
{
    struct bt_node *root = NULL;
    LOG_ENTRY;
    bt_new_node(&root, 2);
    bt_new_node(&root->left, 1);
    bt_new_node(&root->right, 3);
    print_all_nodes(root);
    LOG_EXIT;
    return 0;
}

int build123c()
{
    struct bt_node *root = NULL;
    LOG_ENTRY;
    bst_insert(&root, 2);
    bst_insert(&root, 1);
    bst_insert(&root, 3);
    print_all_nodes(root);
    LOG_EXIT;
    return 0;
}

int main()
{
    build123a();
    build123b();
    build123c();
    return 0;
}
