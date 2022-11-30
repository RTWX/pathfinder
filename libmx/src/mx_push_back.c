#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL) {

        *list = mx_create_node(data);
        return;
    }
    t_list *node = *list;

    for ( ; node->next != NULL; ) {

        node = node->next;
    }
    node->next = mx_create_node(data);
}

