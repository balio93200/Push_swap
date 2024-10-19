#ifndef NODE_H
#define NODE_H
#include <stdio.h>
typedef struct s_node t_node;

typedef struct s_node {
    int value;
    t_node *next;
}   t_node;

t_node *create_new_node(int number);

#endif