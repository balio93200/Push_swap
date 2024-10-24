#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include "turk_algo_utils.h"

void turk_algorithm(t_push_swap *push_swap)
{
    int cheapest_index;
    int correct_pos;

    if (push_swap == NULL)
        return;
    if (push_swap->stack_a.size == 3)
        return (sort_three_elements(push_swap, &push_swap->stack_a));
    if (push_swap->stack_a.size == 4)
        push_b(push_swap);
    else
    {
        push_b(push_swap);
        push_b(push_swap);
    }
    while (push_swap->stack_a.size > 3)
    {
        cheapest_index = find_cheapest(push_swap);
        ft_printf("%d\n", cheapest_index);
        rotate_to_top(&push_swap->stack_a, cheapest_index);
        push_b(push_swap);
    }
    sort_three_elements(push_swap, &push_swap->stack_a);
    while (push_swap->stack_b.size > 0)
    {
        correct_pos = find_position_in_a(&push_swap->stack_a, push_swap->stack_b.head->value);
        rotate_to_top(&push_swap->stack_a, correct_pos);
        push_a(push_swap);
    }
    bring_max_to_bottom(&push_swap->stack_a);

    bring_min_to_top(&push_swap->stack_a);
}
void bring_max_to_bottom(t_stack *stack)
{
    int max_index = find_max_index(stack);
    rotate_to_top(stack, max_index);
    reverse_rotate(stack);
}

int find_max_index(t_stack *stack)
{
    t_node *current = stack->head;
    int max_value = current->value;
    int index = 0;
    int max_index = 0;

    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_index = index;
        }
        current = current->next;
        index++;
    }
    return max_index;
}

int calculate_operations(t_push_swap *push_swap, int value)
{
    int rotations_in_a = find_rotation_count(&push_swap->stack_a, value);
    int rotations_in_b = find_position_in_b(&push_swap->stack_b, value);
    return rotations_in_a + rotations_in_b;
}

void rotate_to_top(t_stack *stack, int index)
{
    if ((size_t)index <= stack->size / 2)
    {
        while (index-- > 0)
            rotate(stack);
    }
    else
    {
        index = stack->size - index;
        while (index-- > 0)
            reverse_rotate(stack);
    }
}

void sort_three_elements(t_push_swap *push_swap, t_stack *stack)
{
    int a = stack->head->value;
    int b = stack->head->next->value;
    int c = stack->head->next->next->value;
    if (a > b && b < c && a < c)
        sa(push_swap);  
    else if (a > b && b > c)
    {
        sa(push_swap);
        rra(push_swap);
        print_stack(push_swap, STACK_A);
    }
    else if (a > b && a > c && b < c)
        ra(push_swap);
    else if (a < b && a > c)
        rra(push_swap);
    else if (a < b && b > c)
    {
        sa(push_swap);
        ra(push_swap);
    }
}

void bring_min_to_top(t_stack *stack)
{
    int min_index = find_min_index(stack);
    rotate_to_top(stack, min_index);
}