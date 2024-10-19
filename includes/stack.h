#include "node.h"
#include <stdlib.h>
#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef struct s_stack {
    t_node *head;
    t_node *tail;
    size_t size;
}   t_stack;

void push(t_stack *f_stack, t_stack *s_stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void clean_stack(t_stack *stack);
void print(t_stack *stack, char *name);
void swap(t_stack *stack);
#endif