#include <stdlib.h>
#include "node.h"
t_node *create_new_node(int number)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if(node == NULL)
    {
        return NULL;
    }
    node->value = number;
    node->next = NULL;
    return node;
}