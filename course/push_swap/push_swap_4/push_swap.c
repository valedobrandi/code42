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

int best_move(Stack *stack, int target)
{
    int index;

    index = stack->top;
    while (index >= 0)
    {
        if (stack->arr[index] == target)
            break;
        index--;
    }
    return (index);
}

int max(Stack *from, int *sorted)
{
    int index = from->top;
    int target = sorted[0];

    while (index >= 0)
    {
        if (target < from->arr[index])
            target = from->arr[index];
        index--;
    }
    return (target);
}

void sorte_back(Stack *from, Stack *to, int *sorted)
{
    int target = 0;
    int position = 0;
    int index = 0;

    while (from->top >= 0)
    {
        target = max(from, sorted);
        position = best_move(from, target);
        if (position > ((from->top + 1) / 2))
            while (from->arr[from->top] != target)
                rotate_top_b(from);
        else
            while (from->arr[from->top] != target)
                rotate_bottom_b(from);
        push_b(from, to);
        index++;
    }
}

Greedy greedy_search(Stack *from, int *sorted, int max, int min, int chunk)
{
    int index = from->top;
    Greedy get;

    get.position = -1;
    get.target = -1;
    while (index > 0)
    {
        if (from->arr[index] <= sorted[max - chunk] &&
            from->arr[index] >= sorted[min - chunk])
        {
            get.position = index;
            get.target = from->arr[index];
            return (get);
        }
        index--;
    }
    return (get);
}

int push_chuncks(Stack *from, Stack *to, int *sorted, int max, int chunk)
{
    int chunck_size = 20;
    Greedy get;
    int index;

    index = 0;
    while (index < chunck_size && from->top > 0)
    {
        get = greedy_search(from, sorted, max, max - chunck_size, chunk);
        if (get.position > ((from->top + 1) / 2))
            while (from->arr[from->top] != get.target)
                rotate_top_a(from);
        else
            while (from->arr[from->top] != get.target)
                rotate_bottom_a(from);
        push_a(from, to);
        index++;
        if (from->top == 0)
            push_a(from, to);
    }
    return (index);
}
