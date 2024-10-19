#include "push_swap.h"

int main(int argc, char **argv)
{
    t_push_swap push_swap;
    init(&push_swap, argc, argv);
    turk_algorithm(&push_swap);
    print_stack(&push_swap, STACK_A);
    clean_up(&push_swap);
}
