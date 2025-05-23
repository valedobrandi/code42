#include "push_swap.h"

void	swap_a(Stack *stack_a)
{
	int	t;

	t = 0;
	if (stack_a->top < 1)
		return;
	t = stack_a->arr[stack_a->top];
	stack_a->arr[stack_a->top] = stack_a->arr[stack_a->top - 1];
	stack_a->arr[stack_a->top - 1] = t;
	print_command("sa");
}

void	swap_b(Stack *stack_b)
{
	int	t;

	t = 0;
	if (stack_b->top < 1)
		return;
	t = stack_b->arr[stack_b->top];
	stack_b->arr[stack_b->top] = stack_b->arr[stack_b->top - 1];
	stack_b->arr[stack_b->top - 1] = t;
	print_command("sb");
}
