#include <stdio.h>

#include "list.h"

int main(int argc, char *argv[], char *envp[])
{
    int print_flags = 0;
    struct slist head;
    struct slist *pos, *prev_pos;
    struct slist *headp = &head;

    pos = prev_pos = NULL;
    print_flags = PRINT_SLIST_FLAG_PRINT_VAL_ONLY;
    print_flags |= PRINT_SLIST_FLAG_SKIP_NL_BW_VAL;
	
    printf("##################################################\n");
    printf("Purpose: delete me if me->next->val is > me->val\n");
    printf("Orig List: 5, 15, 25, 10, 9, 8, 35, 5, 50\n");
    printf("Expected Final List: 25, 10, 9, 35, 50\n");
    
    INIT_NODE(head, 5);
    add_node_end(headp, create_node(15));
    add_node_end(headp, create_node(25));
    add_node_end(headp, create_node(10));
    add_node_end(headp, create_node(9));
    add_node_end(headp, create_node(8));
    add_node_end(headp, create_node(35));
    add_node_end(headp, create_node(5));
    add_node_end(headp, create_node(50));

    for (pos = headp; pos != NULL; pos = pos->next) {
	if (pos->next == NULL)
	    break;
	if (pos->next->val > pos->val) {
	    if (pos != headp) {
		prev_pos->next = pos->next;
	    } else {
		headp = headp->next;
	    }
	}
	prev_pos = pos;
    }
    print_all_slist(headp, print_flags);
}

