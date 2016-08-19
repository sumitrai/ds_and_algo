#include "list.h"

int main()
{
    int print_flags = 0;
    struct slist head;
    struct slist *headp = &head;

    print_flags = PRINT_SLIST_FLAG_PRINT_VAL_ONLY;
    print_flags |= PRINT_SLIST_FLAG_SKIP_NL_BW_VAL;
    
    INIT_NODE(head, 10);
    print_all_slist(headp, print_flags);
    add_node_beg(&headp, create_node(20));
    add_node_beg(&headp, create_node(30));
    add_node_beg(&headp, create_node(40));
    print_all_slist(headp, print_flags);
    add_node_end(headp, create_node(9));
    add_node_end(headp, create_node(4));
    print_all_slist(headp, print_flags);
    add_node_pos(&headp, create_node(5), 5);
    add_node_pos(&headp, create_node(1), 1);
    add_node_pos(&headp, create_node(200), 200);
    print_all_slist(headp, print_flags);
}
