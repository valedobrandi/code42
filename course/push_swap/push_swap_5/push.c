#include "push_swap.h"

char *push_a(Stack *stack_a, Stack *stack_b)
{
    int popped;

    popped = pop(stack_a);
    printf("PUSH %d\n", popped);
    push(stack_b, popped);
    increment_count();
    return ("sa");
}

char *push_b(Stack *stack_b, Stack *stack_a)
{
    int popped;

    popped = pop(stack_b);
    printf("PUSH %d\n", popped);
    push(stack_a, popped);
    increment_count();
    return ("sb");
}