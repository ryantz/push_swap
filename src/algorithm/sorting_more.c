#include "algorithm.h"

int ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
    int min;
    int i;

    // Find and push the minimum to b
    min = ft_find_min(*stack_a);
    i = 0;
    while ((*stack_a)->content != min)
    {
        ft_rotate_single(stack_a, 'a');
        i++;
    }
    ft_push_top_b(stack_a, stack_b);

    // Sort remaining 3
    ft_sort_three(stack_a);

    // Push min back to top of a
    ft_push_top_a(stack_a, stack_b);
    return (0);
}

int ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int min;

    // Push two smallest to b
    min = ft_find_min(*stack_a);
    while ((*stack_a)->content != min)
        ft_rotate_single(stack_a, 'a');
    ft_push_top_b(stack_a, stack_b);

    min = ft_find_min(*stack_a);
    while ((*stack_a)->content != min)
        ft_rotate_single(stack_a, 'a');
    ft_push_top_b(stack_a, stack_b);

    // Sort remaining 3
    ft_sort_three(stack_a);

    // Push back — larger of the two first so smaller ends on top
    if ((*stack_b)->content > (*stack_b)->next->content)
        ft_swap_single(stack_b, 'b');
    ft_push_top_a(stack_a, stack_b);
    ft_push_top_a(stack_a, stack_b);
    return (0);
}
