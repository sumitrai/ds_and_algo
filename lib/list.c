#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "list.h"

void print_all_slist(struct slist *head)
{
    struct slist *pos = NULL;

    printf("=\n");
    for_each_node(pos, head) {
        PRINT_NODE(pos);
    }
    printf("=\n");
}

struct slist *create_node(int val)
{
    struct slist *node = malloc(SIZEOF_SLIST);
    node->next = NULL;
    node->val = val;
    return node;
}

void add_node_beg(struct slist **head, struct slist *node)
{
    assert(head != NULL);
    assert(node != NULL);
    
    void *tmp = *head;
    node->next = *head; 
    *head = node;

}

void add_node_end(struct slist *head, struct slist *node)
{
    struct slist *pos, *prev_pos;

     pos = prev_pos = NULL;

    for (pos = head; pos != NULL; pos = pos->next)
	prev_pos = pos;

    if (prev_pos) {
	prev_pos->next = node;
	node->next = NULL;
    }
}
