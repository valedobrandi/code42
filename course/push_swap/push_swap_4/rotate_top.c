#include "push_swap.h"

void	rotate_top_a(Stack *stack_a)
{
	int	index;
	int	top;

	if (stack_a->top < 1)
		return;
	top = stack_a->arr[stack_a->top];
	index = stack_a->top;
	while (index > 0)
	{
		stack_a->arr[index] = stack_a->arr[index - 1];
		index--;
	}
	stack_a->arr[0] = top;
	print_command("rra");
}

void	rotate_top_b(Stack *stack_b)
{
	int	index;
	int	top;

	if (stack_b->top < 1)
		return;
	top = stack_b->arr[stack_b->top];
	index = stack_b->top;
	while (index > 0)
	{
		stack_b->arr[index] = stack_b->arr[index - 1];
		index--;
	}
	stack_b->arr[0] = top;
	print_command("rrb");
}
