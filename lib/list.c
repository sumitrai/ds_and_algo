/**
 *
 */
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
    
    node->next = *head; 
    *head = node;
}

void add_node_end(struct slist *head, struct slist *node)
{
    assert(head != NULL);
    assert(node != NULL);
    
    struct slist *pos, *prev_pos;

     pos = prev_pos = NULL;

    for (pos = head; pos != NULL; pos = pos->next)
	prev_pos = pos;

    if (prev_pos) {
	prev_pos->next = node;
	node->next = NULL;
    }
}

/* if pos > length of linked list, insert at the end */ 
void add_node_pos(struct slist **head, struct slist *node, int insert_at_pos)
{
    assert(head != NULL);
    assert(node != NULL);
    
    int count;
    struct slist *pos, *prev_pos;
    struct slist *headp = *head;

    pos = prev_pos = NULL;

    // fix invalid user input
    if (insert_at_pos <= 0)
	insert_at_pos = 1;
    
    for (count = 1, pos = headp; (pos != NULL) && (count != insert_at_pos);
         pos = pos->next, count++) {
	prev_pos = pos;
    }

    node->next = pos;
    
    // insert at postion 1: make node the new head
    if (pos == headp) {
	*head = node;
    } else {
	prev_pos->next = node;
    }
}
