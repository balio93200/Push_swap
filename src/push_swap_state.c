#include "push_swap.h"
#include "libft.h"

void init(t_push_swap *push_swap, int ac, char **av)
{
    (void)ac;
    ft_memset(push_swap, 0, sizeof(t_push_swap));
    char **numbers = ft_split(av[1], ' ');
    size_t i = 0;
    int number;
    t_stack *stack_a = &push_swap->stack_a;
    while(numbers[i])
    {
        number = ft_atoi(numbers[i]);
        t_node *node = create_new_node(number);
        if (stack_a->head == NULL)
        {
            stack_a->head = node;
            stack_a->tail = node;
        }
        else
        {
            stack_a->tail->next=node;
            stack_a->tail=node;
        }
        stack_a->size++;
        i++;
    }
    i = 0;
    while(numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

void clean_up(t_push_swap *push_swap)
{
    clean_stack(&push_swap->stack_a);
    clean_stack(&push_swap->stack_b);
}

void print_stack(t_push_swap *push_swap, enum STACK_NAME stack_name)
{
    if (stack_name == STACK_A)
    {
        print(&push_swap->stack_a, "a");
        return;
    }
    else
    {
        print(&push_swap->stack_b, "b");
    }
}