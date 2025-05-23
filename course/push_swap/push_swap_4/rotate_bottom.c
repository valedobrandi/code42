#include "push_swap.h"

void	rotate_bottom_a(Stack *stack_a)
{
	int	index;
	int	bottom;

	if (stack_a->top < 1)
		return;
	bottom = stack_a->arr[0];
	index = 0;
	while (index < stack_a->top)
	{
		stack_a->arr[index] = stack_a->arr[index + 1];
		index++;
	}
	stack_a->arr[stack_a->top] = bottom;
	print_command("ra");
}

void	rotate_bottom_b(Stack *stack_b)
{
	int index;
	int bottom;

	if (stack_b->top < 1)
		return;
	bottom = stack_b->arr[0];
	index = 0;
	while (index < stack_b->top)
	{
		stack_b->arr[index] = stack_b->arr[index + 1];
		index++;
	}
	stack_b->arr[stack_b->top] = bottom;
	print_command("rb");
}
