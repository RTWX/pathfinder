#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *) ) {
    if (list == NULL)
        return NULL;
    int x = mx_list_size(list);

    for (int i = 0; i < x; i++) {

        t_list *node = list;
        t_list *prevNode = NULL;

        for ( ; node->next != NULL; ) {
            if ( cmp(node->data, node->next->data) ) { // 1 -> 2 -> 3 -> 4 = 1 -> 3 -> 2 -> 4//pn-> n -> nn-> nnn
                
                if (prevNode != NULL)
                    prevNode->next = node->next;//1->3
                else 
                    list = node->next;

                t_list *tempNode1 = node;
                t_list *tempNode2 = node->next;

                if (node->next->next != NULL)
                    tempNode1->next = node->next->next;
                else
                    tempNode1->next = NULL;
                tempNode2->next = tempNode1;
                node = tempNode2;
            }
            prevNode = node;
            node = node->next;
        }
    }
    return list;
}


