#include "push_swap.h"

int operation_count = 0;

void increment_count()
{
    operation_count++;
}

int validate(Stack *stack)
{
    int index;

    index = 0;
    while (index < stack->top)
    {
        if (stack->arr[stack->top] < stack->arr[index])
            return (0);
        index++;
    }
    return (1);
}

void pa(Stack *stack, Stack *b)
{
    int popped;

    popped = pop(stack);
    push(b, popped);
    increment_count();
}

void sa(Stack *stack)
{
    int t = 0;

    if (stack->top < 1)
        return;
    t = stack->arr[stack->top];
    stack->arr[stack->top] = stack->arr[stack->top - 1];
    stack->arr[stack->top - 1] = t;
    increment_count();
}

void rotate_bottom(Stack *stack)
{
    int index;
    int bottom;

    if (stack->top < 1)
        return;
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

void rotate_top(Stack *stack)
{
    int index;
    int top;

    if (stack->top < 1)
        return;
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

int best_move(Stack *stack, int target)
{
    int index;

    index = stack->top;
    while (index >= 0)
    {
        if (stack->arr[index] == target)
            return (index);
        index--;
    }
    return (0);
}

int find_in_chunk(Stack *from, int *sorted, int max, int min, int chunk)
{
    int index = from->top;
    while (index >= 0)
    {
        if (from->arr[index] <= sorted[max - chunk - 1] ||
            from->arr[index] >= sorted[min - chunk])
            break;
        index--;
    }
    return (index);
}

int find_index(int *sorted, int size, int target)
{
    int index = 0;

    while (index < size)
    {
        if (sorted[index] == target)
            return (index);
        index++;
    }
    return (-1);
}

void best_rotate(Stack *stack, int target, int current)
{
    if (target > ((stack->top + 1) / 2))
        while (stack->arr[stack->top] != current)
            rotate_top(stack);
    else
        while (stack->arr[stack->top] != current)
            rotate_bottom(stack);
}

void sort_a(Stack *from, Stack *to, int *sorted)
{
    int current = 0;
    int next_move = 0;
    int index = 0;
    int target = 0;
    int find_next = 0;
    int find_prev = 0;

    while (from->top > -1)
    {

        current = find_index(sorted, 99, from->arr[from->top]);
        find_next = find_index(to->arr, to->top, sorted[current + 1]);
        find_prev = find_index(to->arr, to->top, sorted[current - 1]);
        if (find_next != -1)
        {
            target = best_move(to, sorted[current + 1]);
            best_rotate(to, target,  sorted[current + 1]);
        }
        else if (find_prev != -1)
        {
            target = best_move(to, sorted[current - 1]);
            best_rotate(to, target, sorted[current - 1]);
        }
        pa(from, to);
        index++;
    }
}

void push_chuncks(Stack *from, Stack *to, int *sorted)
{
    int chunk_size = 20;
    int chunk = 0;
    int max = 100;
    int min = 80;
    int index;

    while (from->top >= 0)
    {
        index = 0;
        while (index < chunk_size)
        {
            if (from->arr[from->top] <= sorted[max - chunk - 1] &&
                from->arr[from->top] >= sorted[min - chunk])
            {
                pa(from, to);
                index++;
            }
            else
            {
                int target = 0;
                int chunck_value = find_in_chunk(from, sorted, max, min, chunk);
                if (chunck_value > ((from->top + 1) / 2))
                    while (!(from->arr[from->top] <= sorted[max - chunk - 1]) ||
                           !(from->arr[from->top] >= sorted[min - chunk]))
                        rotate_top(from);
                else
                    while (!(from->arr[from->top] <= sorted[max - chunk - 1]) ||
                           !(from->arr[from->top] >= sorted[min - chunk]))
                        rotate_bottom(from);
            }
        }
        chunk += 20;
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
    printf("\nTotal operations: %d\n", operation_count);
    printf("-----\n");
    sort_a(&temp, &stack, sorted);
    for (int i = 0; i < 100; i++)
        printf("[A][%d] - %d\n", i, temp.arr[i]);
    printf("\nTotal operations: %d\n", operation_count);
    printf("\n");

    return (0);
}