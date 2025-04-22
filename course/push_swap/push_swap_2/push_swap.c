#include "push_swap.h"

int		operation_count = 0;

void	increment_count(void)
{
	operation_count++;
}

int	validate(Stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->top)
	{
		if (stack->arr[stack->top] < stack->arr[index])
			return (0);
		index++;
	}
	return (1);
}

void	pa(Stack *stack, Stack *b)
{
	int	popped;

	popped = pop(stack);
	push(b, popped);
	increment_count();
}

void	sa(Stack *stack)
{
	int	t;

	t = 0;
	if (stack->top < 1)
		return ;
	t = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = t;
	increment_count();
}

void	rotate_bottom(Stack *stack)
{
	int	index;
	int	bottom;

	if (stack->top < 1)
		return ;
	bottom = stack->arr[0];
	index = 0;
	while (index < stack->top)
	{
		stack->arr[index] = stack->arr[index + 1];
		index++;
	}
	stack->arr[stack->top] = bottom;
	increment_count();
}

void	rotate_top(Stack *stack)
{
	int	index;
	int	top;

	if (stack->top < 1)
		return ;
	top = stack->arr[stack->top];
	index = stack->top;
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		index--;
	}
	stack->arr[0] = top;
	increment_count();
}

void	swap(Stack *from, Stack *to, int middle)
{
	if (from->arr[from->top] >= middle)
		pa(from, to);
	else
		rotate_bottom(from);
}

int	best_move(Stack *stack, int target)
{
	int	index;

	index = stack->top;
	while (index < stack->top)
	{
		if (stack->arr[index] == target)
			break ;
		index++;
	}
	return (index);
}

int	find_index(int *sorted, int target)
{
	int	index;

	index = 0;
	while (*sorted)
	{
		if (sorted[index] == target)
			return (index);
		index++;
	}
	return (index);
}

void	push_back(Stack *from, Stack *to, int *sorted)
{
	int	target;
	int	next;
	int	position;

	target = 0;
	next = 0;
	position = 0;
	while (from->top > -1)
	{
		target = to->arr[to->top];
		next = from->arr[from->top];
		if (next > target)
			pa(from, to);
		else
			rotate_bottom(to);
	}
}

int	find_chunk(Stack *from, int *sorted, int max, int min)
{
	int	index;

	index = from->top;
	while (index >= 0)
	{
		if (from->arr[from->top] <= sorted[max - 1]
			|| from->arr[from->top] >= sorted[min])
			break ;
		index--;
	}
	return (index);
}

void	push_swap(Stack *from, Stack *to, int *sorted)
{
	int	chunk_size;
	int	max;
	int	min;
	int	index;
	int	chunck_value;
	int	target;

	chunk_size = 20;
	max = from->top / 2;
	min = 0;
	while (from->top >= max)
	{
		index = 0;
		chunck_value = find_chunk(from, sorted, max, min);
		if (from->arr[from->top] <= sorted[max - 1]
			&& from->arr[from->top] >= sorted[min])
		{
			pa(from, to);
			index++;
		}
		else
		{
			target = 0;
			if (chunck_value > ((from->top + 1) / 2))
				while (!(from->arr[from->top] <= sorted[max - 1])
					|| !(from->arr[from->top] >= sorted[min]))
					rotate_top(from);
			else
				while (!(from->arr[from->top] <= sorted[max - 1])
					|| !(from->arr[from->top] >= sorted[min]))
					rotate_bottom(from);
		}
	}
}


int main(void)
{
    Stack stack = {
        .arr = {3, 27, 94, 19, 63, 1, 88, 52, 44, 85,
                7, 90, 33, 39, 60, 101, 48, 96, 59, 18,
                34, 40, 58, 15, 6, 92, 87, 100, 50, 26,
                76, 46, 32, 10, 14, 69, 2, 64, 25, 43,
                28, 84, 36, 21, 66, 30, 78, 82, 37, 45,
                77, 16, 4, 5, 35, 93, 74, 47, 9, 95,
                20, 24, 11, 80, 56, 41, 86, 13, 38, 75,
                71, 23, 31, 67, 91, 17, 72, 61, 12, 97,
                65, 42, 70, 29, 53, 55, 22, 99, 49, 83,
                8, 68, 81, 57, 62, 98, 89, 54, 79},
        .top = 99};
    Stack temp = {.top = -1};
    int *sorted = buble_sort(stack.arr, 100);
    push_chuncks(&stack, &temp, sorted);
    for (int i = 0; i < 100; i++)
        printf("[B][%d] - %d\n", i, temp.arr[i]);
    printf("-----\n");
/*     sort_a(&temp, &stack, sorted);
    for (int i = 0; i < 100; i++)
        printf("[A][%d] - %d\n", i, temp.arr[i]); */
    printf("\nTotal operations: %d\n", operation_count);
    printf("\n");

    return (0);
}
