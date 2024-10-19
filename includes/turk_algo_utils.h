#ifndef TURK_ALGO_UTILS_H
#define TURK_ALGO_UTILS_H
#include "push_swap.h"

int find_cheapest(t_push_swap *push_swap);
int find_rotation_count(t_stack *stack, int number);
int find_position_in_b(t_stack *stack_b, int number);
int find_position_in_a(t_stack *stack_a, int number);
int find_min_index(t_stack *stack);
#endif