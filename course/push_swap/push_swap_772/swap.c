#include "push_swap.h"

char *swap_a(Stack *stack_a)
{
    int t = 0;

    if (stack_a->top < 1)
        return (NULL);
    t = stack_a->arr[stack_a->top];
    stack_a->arr[stack_a->top] = stack_a->arr[stack_a->top - 1];
    stack_a->arr[stack_a->top - 1] = t;
    increment_count();
    return ("sa");
}

char *swap_b(Stack *stack_b)
{
    int t = 0;

    if (stack_b->top < 1)
        return (NULL);
    t = stack_b->arr[stack_b->top];
    stack_b->arr[stack_b->top] = stack_b->arr[stack_b->top - 1];
    stack_b->arr[stack_b->top - 1] = t;
    increment_count();
    return ("sb");
}