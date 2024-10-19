#include "stack.h"
#include "ft_printf.h"
void push(t_stack *f_stack, t_stack *s_stack)
{
    if (s_stack->size == 0 || f_stack == s_stack)
        return;
    t_node *new_head = s_stack -> head -> next;
    s_stack -> head -> next = f_stack -> head;
    f_stack -> head = s_stack -> head;
    s_stack -> head = new_head;
    s_stack->size--;
    f_stack->size++;
    if (f_stack->size == 1)
    {
        f_stack->tail = f_stack->head;
    }
    else if (s_stack->size == 0)
    {
        s_stack->tail = NULL;
    }
}

void rotate(t_stack *stack)
{
    if (stack -> size < 2)
        return;
    t_node *head;
    t_node *tail;

    head = stack->head;
    tail = stack->tail;
    stack->head = head->next;
    head->next = NULL;
    tail->next = head;
    stack->tail = head;
} 

void clean_stack(t_stack *stack)
{
    t_node *node;
    t_node *next;
    node = stack->head;
    while(node != NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }
}

void print(t_stack *stack, char *name)
{
    t_node *node;

    ft_printf("stack %s\n", name);
    node = stack -> head;
    while (node != NULL)
    {
        ft_printf("%d\n", node->value);
        node = node -> next;
    }
    ft_printf("End stack %s\n\n", name);
}

void swap(t_stack *stack)
{
    if (stack->size < 2)
        return;

    t_node *first = stack->head;      
    t_node *second = first->next;      

    first->next = second->next;      
    second->next = first;             

    stack->head = second;

    if (stack->size == 2)
    {
        stack->tail = first;
    }
}

void reverse_rotate(t_stack *stack)
{
    t_node *current;
    t_node *tail;

    if (stack->size < 2)
        return;
    current = stack->head;
    tail = stack->tail;
    while (current->next != tail)
        current = current->next;
    stack->tail->next = stack->head;
    stack->head = stack->tail;
    current->next = NULL;
    stack->tail = current;
}