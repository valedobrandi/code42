#include "../philo.h"

void	push(t_stack *stack, void *value)
{
	if (stack->top >= stack->size - 1)
		return;
	stack->arr[++stack->top] = value;
}

void	*pop(t_stack *stack)
{
	if (stack->top < 0)
		return (NULL);
	return (stack->arr[stack->top--]);
}

int init_stack(t_stack *stack, int capacity)
{
	stack->arr = malloc(sizeof(void *) * capacity);
	if (stack->arr == NULL)
	{
		stack->size = 0;
		stack->top = -1;
		return (0);
	}
	stack->top = -1;
	stack->size = capacity;
	return (1);
}