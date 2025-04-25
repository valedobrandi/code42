#include "push_swap.h"

char *rotate_bottom_a(Stack *stack_a)
{
    int index;
    int bottom;

    if (stack_a->top < 1)
        return (NULL);
    bottom = stack_a->arr[0].value;
    index = 0;
    while (index < stack_a->top)
    {
        stack_a->arr[index] = stack_a->arr[index + 1];
        index++;
    }
    stack_a->arr[stack_a->top].value = bottom;
    increment_count();
    return ("ra");
}

char *rotate_bottom_b(Stack *stack_b)
{
    int index;
    int bottom;

    if (stack_b->top < 1)
        return (NULL);
    bottom = stack_b->arr[0].value;
    index = 0;
    while (index < stack_b->top)
    {
        stack_b->arr[index] = stack_b->arr[index + 1];
        index++;
    }
    stack_b->arr[stack_b->top].value = bottom;
    increment_count();
    return ("rb");
}