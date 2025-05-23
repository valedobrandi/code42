#include "push_swap.h"

void	push_a(Stack *stack_a, Stack *stack_b)
{
	int	popped;

	popped = pop(stack_a);
	push(stack_b, popped);
	write(1, "pa\n", 3);
}

void	push_b(Stack *stack_b, Stack *stack_a)
{
	int	popped;

	popped = pop(stack_b);
	push(stack_a, popped);
	write(1, "pb\n", 3);
}
