#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
void push_a(t_push_swap *push_swap)
{
    push(&push_swap->stack_a, &push_swap->stack_b);
    ft_printf("pa\n");
}

void push_b(t_push_swap *push_swap)
{
    push(&push_swap->stack_b, &push_swap->stack_a);
    ft_printf("pb\n");
}

void ra(t_push_swap *push_swap)
{
    rotate(&push_swap->stack_a);
    ft_printf("ra\n");
}

void rb(t_push_swap *push_swap)
{
    rotate(&push_swap->stack_b);
    ft_printf("rb\n");
}

void rra(t_push_swap *push_swap)
{
    reverse_rotate(&push_swap->stack_a);
    ft_printf("rra\n");
}

void rrb(t_push_swap *push_swap)
{
    reverse_rotate(&push_swap->stack_b);
    ft_printf("rra\n");
}

void sa(t_push_swap *push_swap)
{
    swap(&push_swap->stack_a);
    ft_printf("sa\n");
}

void sb(t_push_swap *push_swap)
{
    swap(&push_swap->stack_b);
    ft_printf("sb\n");
}

void ss(t_push_swap *push_swap)
{
    swap(&push_swap->stack_a);
    swap(&push_swap->stack_b);
    ft_printf("ss\n");
}