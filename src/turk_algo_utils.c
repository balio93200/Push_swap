#include "push_swap.h"
int find_min_index(t_stack *stack)
{
    int min_value = stack->head->value;
    int min_index = 0;
    int index = 0;

    t_node *current = stack->head;
    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return min_index;
}


int find_position_in_a(t_stack *stack_a, int number)
{
    t_node *current;
    int position = 0;
    
    if (stack_a->size == 0)
        return 0;

    current = stack_a->head;
    
    if (number < current->value && number > stack_a->tail->value)
        return 0;

    while (current->next != NULL)
    {
        if (number > current->value && number < current->next->value)
            return position + 1;
        current = current->next;
        position++;
    }
    return position + 1;
}

int find_position_in_b(t_stack *stack_b, int number)
{
    if (stack_b->size == 0)
        return 0;

    t_node *current = stack_b->head;
    int position = 0;

    if (number > current->value && number < stack_b->tail->value)
        return 0;

    while (current->next != NULL)
    {
        if (number < current->value && number > current->next->value)
            return position + 1;
        current = current->next;
        position++;
    }
    return position + 1;
}


int find_rotation_count(t_stack *stack, int number)
{
    t_node *current = stack->head;
    int rotation_count = 0;

    while (current != NULL)
    {
        if (current->value > number && current->next != NULL && current->next->value < number)
            break;

        current = current->next;
        rotation_count++;
    }
    return rotation_count;
}

int find_cheapest(t_push_swap *push_swap)
{
    int min_operations = INT_MAX;
    int cheapest_index = 0;
    int index = 0;

    t_node *current = push_swap->stack_a.head;
    while (current != NULL)
    {
        int operations = calculate_operations(push_swap, current->value);
        if (operations < min_operations)
        {
            min_operations = operations;
            cheapest_index = index;
        }
        current = current->next;
        index++;
    }
    return cheapest_index;
}
