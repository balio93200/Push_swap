#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "stack.h"
#include <stdio.h>
#include <limits.h>
typedef struct s_push_swap {
    t_stack stack_a;
    t_stack stack_b;
}   t_push_swap;

enum STACK_NAME {
    STACK_A,
    STACK_B
} ;

void init(t_push_swap *push_swap, int argc, char **argv);
void push_a(t_push_swap *push_swap);
void push_b(t_push_swap *push_swap);
void ra(t_push_swap *push_swap);
void rb(t_push_swap *push_swap);
void print(t_stack *stack, char *name);
void clean_up(t_push_swap *push_swap);
void print_stack(t_push_swap *push_swap, enum STACK_NAME stack_name);
void turk_algorithm(t_push_swap *push_swap);
int calculate_operations(t_push_swap *push_swap, int value);
void rotate_to_top(t_stack *stack, int index);
void sort_three_elements(t_push_swap *push_swap, t_stack *stack);
void bring_min_to_top(t_stack *stack);
void reverse_rotate(t_stack *stack);
void sa(t_push_swap *push_swap);
void sb(t_push_swap *push_swap);
void ss(t_push_swap *push_swap);
void rra(t_push_swap *push_swap);
void rrb(t_push_swap *push_swap);
#endif