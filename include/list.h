#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

/* Generic key-value item. */
typedef struct
{
    char *key;
    int value;
} item;

struct slist {
    int val;
    struct slist *next;
};

#define PRINT_SLIST_FLAG_PRINT_VAL_ONLY  0x01
#define PRINT_SLIST_FLAG_SKIP_NL_BW_VAL  0x02

#define INIT_NODE(node, value) \
    node.next = NULL; node.val = value
#define SIZEOF_SLIST (sizeof(struct slist))
#define for_each_node(pos, head) \
    for (pos = head; pos != NULL; pos = pos->next)
#define PRINT_NODE(node) \
    printf("%p: %d\n", node, node->val)

void print_all_slist(struct slist *head, int flags);
struct slist *create_node(int val);
void add_node_beg(struct slist **head, struct slist *node);
void add_node_end(struct slist *head, struct slist *node);
void add_node_pos(struct slist **head, struct slist *node, int insert_at_pos);
#endif
